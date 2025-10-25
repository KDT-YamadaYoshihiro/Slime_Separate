#include "InGame.h"
#include "Load.h"
#include "mouse.h"
#include "DxLib.h"
#include <algorithm>

// コンストラクタ
InGame::InGame()
    : elapsed_time(repursue * 60),m_blue_image(-1), m_red_image(-1),
    m_spawn_timer(0), m_spawn_interval(repursue * 8), m_max_slime(1), m_spawn_slime(0), m_score(0)
{
}

// 初期化
void InGame::Init() {
    bg = std::make_shared<DrawImage>(0, 0, 1280, 720, Load::Instance().GetBgGrh());
    m_left_area = std::make_shared<CaseArea>(0, 300, 200, 200, 0);
    m_right_area = std::make_shared<CaseArea>(1080, 300, 200, 200, 1);
    m_blue_image = Load::Instance().GetBlueSlimeGrh();
    m_red_image = Load::Instance().GetRedSlimeGrh();
}

// 更新
void InGame::Update() {

    elapsed_time--;

    if (elapsed_time <= repursue * 40) {
        m_spawn_interval = repursue * 7;
    }
    else if (elapsed_time <= repursue * 20) {
        m_spawn_interval = repursue * 6;
    }
    else if (elapsed_time <= repursue * 10) {
        m_spawn_interval = repursue * 5;
    }
    else
    {
        m_spawn_interval = repursue * 8;

    }

    m_spawn_timer++;

    if (m_spawn_timer >= m_spawn_interval ) {

        while (m_spawn_slime < m_max_slime)
        {
            SpawnSlime();
            m_spawn_slime++;
        }

        m_max_slime++;
        m_max_slime = min(5, m_max_slime);
        m_spawn_slime = 0;
        m_spawn_timer = 0;
    }

    int mouse_x, mouse_y;
    GetMousePoint(&mouse_x, &mouse_y);
    bool mouseDown = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;

    // ドラッグ開始判定
    if (!m_dragged_slime && mouseDown) {
        for (auto& slime : m_slimes) {
            if (!slime->IsDragging() && CheckCircleClick(slime->GetX(), slime->GetY(), 100)) {
                m_dragged_slime = slime;
                slime->SetDragging(true);
                break;
            }
        }
    }

    // スライム更新
    m_left_area->ResetCount();
    m_right_area->ResetCount();

    for (auto& slime : m_slimes) {
        // ドラッグ中以外は通常更新
        if (slime != m_dragged_slime) {
            slime->Update();

            // Case判定
            int cx = slime->GetX() + slime->GetWidth() / 2;
            int cy = slime->GetY() + slime->GetHeight() / 2;

            bool inLeft = m_left_area->IsInside(cx, cy);
            bool inRight = m_right_area->IsInside(cx, cy);

            if (inLeft) {
                slime->SetExplosionFlag(slime->GetType() == m_left_area->GetType());
                m_left_area->AddSlime();
                m_left_area->PushOut(slime->GetX(), slime->GetY(), slime->GetWidth(), slime->GetHeight());
            }
            else if (inRight) {
                slime->SetExplosionFlag(slime->GetType() == m_right_area->GetType());
                m_right_area->AddSlime();
                m_right_area->PushOut(slime->GetX(), slime->GetY(), slime->GetWidth(), slime->GetHeight());
            }
            else {
                // Case外なら通常押し出し
                m_left_area->PushOut(slime->GetX(), slime->GetY(), slime->GetWidth(), slime->GetHeight());
                m_right_area->PushOut(slime->GetX(), slime->GetY(), slime->GetWidth(), slime->GetHeight());
            }
        }
    }

    // ドラッグ中のスライム移動
    if (m_dragged_slime) {
        m_dragged_slime->DrugMove(mouse_x, mouse_y);
        if (!mouseDown) {
            m_dragged_slime->SetDragging(false);
            m_dragged_slime = nullptr;
        }
    }

    // 生きていないスライムを削除
    m_slimes.erase(
        std::remove_if(m_slimes.begin(), m_slimes.end(),
            [](std::shared_ptr<Slime>& s) { return !s->IsAlive(); }),
        m_slimes.end()
    );

    // スコア換算
    m_score = m_left_area->GetCount() + m_right_area->GetCount();
}

// 描画
void InGame::Render() {
    bg->SizeDraw();
    m_left_area->Draw();
    m_right_area->Draw();

    for (auto& slime : m_slimes)
        slime->Draw();
}

// スライムスポーン
void InGame::SpawnSlime() {
    int type = GetRand(1);
    int img = (type == 0) ? m_blue_image : m_red_image;

    int x, y;
    do {
        x = GetRand(1180);
        y = GetRand(620);
    } while (m_left_area->IsInside(x, y, 80, 80) || m_right_area->IsInside(x, y, 100, 100));

    auto s = m_pool.Acquire();
    s->Start(x, y, 100, 100, img, EnemyState::MOVE, type);
    m_slimes.push_back(s);
}
