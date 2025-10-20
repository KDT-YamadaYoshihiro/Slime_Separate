#include "InGame.h"
#include "Load.h"
#include "mouse.h"
#include "DxLib.h"
#include <algorithm>

InGame::InGame()
    : m_blueImage(-1), m_redImage(-1),
    m_spawnTimer(0), m_spawnInterval(180), m_maxSlime(5), m_score(0)
{
}

void InGame::Init() {
    bg = std::make_shared<DrawImage>(0, 0, 1280, 720, Load::Instance().GetBgGrh());
    m_leftArea = std::make_shared<CaseArea>(0, 300, 200, 200, 0);
    m_rightArea = std::make_shared<CaseArea>(1080, 300, 200, 200, 1);
    m_blueImage = Load::Instance().GetBlueSlimeGrh();
    m_redImage = Load::Instance().GetRedSlimeGrh();
}

void InGame::Update() {
    m_spawnTimer++;
    if (m_spawnTimer >= m_spawnInterval && (int)m_slimes.size() < m_maxSlime) {
        SpawnSlime();
        m_spawnTimer = 0;
    }

    int mouse_x, mouse_y;
    GetMousePoint(&mouse_x, &mouse_y);
    bool mouseDown = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;

    // ドラッグ開始判定
    if (!m_draggedSlime && mouseDown) {
        for (auto& slime : m_slimes) {
            if (!slime->IsDragging() && CheckCircleClick(slime->GetX(), slime->GetY(), 100)) {
                m_draggedSlime = slime;
                slime->SetDragging(true);
                break;
            }
        }
    }

    // スライム更新
    m_leftArea->ResetCount();
    m_rightArea->ResetCount();

    for (auto& slime : m_slimes) {
        // ドラッグ中以外は通常更新
        if (slime != m_draggedSlime) {
            slime->Update();

            // Case判定
            int cx = slime->GetX() + slime->GetWidth() / 2;
            int cy = slime->GetY() + slime->GetHeight() / 2;

            bool inLeft = m_leftArea->IsInside(cx, cy);
            bool inRight = m_rightArea->IsInside(cx, cy);

            if (inLeft) {
                slime->SetExplosionFlag(slime->GetType() == m_leftArea->GetType());
                m_leftArea->AddSlime();
                m_leftArea->PushOut(slime->GetX(), slime->GetY(), slime->GetWidth(), slime->GetHeight());
            }
            else if (inRight) {
                slime->SetExplosionFlag(slime->GetType() == m_rightArea->GetType());
                m_rightArea->AddSlime();
                m_rightArea->PushOut(slime->GetX(), slime->GetY(), slime->GetWidth(), slime->GetHeight());
            }
            else {
                // Case外なら通常押し出し
                m_leftArea->PushOut(slime->GetX(), slime->GetY(), slime->GetWidth(), slime->GetHeight());
                m_rightArea->PushOut(slime->GetX(), slime->GetY(), slime->GetWidth(), slime->GetHeight());
            }
        }
    }

    // ドラッグ中のスライム移動
    if (m_draggedSlime) {
        m_draggedSlime->DrugMove(mouse_x, mouse_y);
        if (!mouseDown) {
            m_draggedSlime->SetDragging(false);
            m_draggedSlime = nullptr;
        }
    }

    // 生きていないスライムを削除
    m_slimes.erase(
        std::remove_if(m_slimes.begin(), m_slimes.end(),
            [](std::shared_ptr<Slime>& s) { return !s->IsAlive(); }),
        m_slimes.end()
    );

    // スコア換算
    m_score = m_leftArea->GetCount() + m_rightArea->GetCount();
}


void InGame::Render() {
    bg->SizeDraw();
    m_leftArea->Draw();
    m_rightArea->Draw();

    for (auto& slime : m_slimes)
        slime->Draw();
}

void InGame::SpawnSlime() {
    int type = GetRand(1);
    int img = (type == 0) ? m_blueImage : m_redImage;
    int x = GetRand(1180);
    int y = GetRand(620);

    auto s = m_pool.Acquire(); // shared_ptr
    s->Start(x, y, 100, 100, img, EnemyState::MOVE, type);
    m_slimes.push_back(s);
}

void InGame::CheckSort(std::shared_ptr<Slime> slime) {
    // ここにスコア換算やケース判定を追加可能
}
