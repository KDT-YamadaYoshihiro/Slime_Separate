#include "InGame.h"
#include "Load.h"
#include "mouse.h"
#include "DxLib.h"
#include <algorithm>

// コンストラクタ
InGame::InGame()
    : m_phase(TITLE), elapsed_time(M_REFRESH_RATE * 60), m_blue_image(-1), m_red_image(-1),
    m_spawn_timer(0), m_spawn_interval(M_REFRESH_RATE * 8), m_max_slime(1), m_spawn_slime(0), m_return_slime(0), m_score(0)
{
}

// 初期化
void InGame::Init() {
    bg = std::make_shared<DrawImage>(0, 0, 1280, 720, Load::Instance().GetBgGrh());
    m_left_area = std::make_shared<CaseArea>(0, 300, 200, 200, 0);
    m_right_area = std::make_shared<CaseArea>(1080, 300, 200, 200, 1);
    m_blue_image = Load::Instance().GetBlueSlimeGrh();
    m_red_image = Load::Instance().GetRedSlimeGrh();

    m_phase = TITLE;

}

// 更新
void InGame::Update() {


    switch (m_phase)
    {
    case TITLE:

        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) { // 左クリックが押された場合
            m_phase = INGAME;
        }


        break;

    case INGAME:

        // タイム更新
        TimeUpdate();

        // スライム更新
        SlimeUpdate();

        // スコア換算
        m_score = (m_left_area->GetCount() + m_right_area->GetCount() + m_return_slime) * M_SCORE;


        break;

    case RESULT:

        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) { // 左クリックが押された場合
            DxLib_End();
        }


        break;
    default:
        break;
    }

}

void InGame::SlimeUpdate()
{

    // 残り時間に合わせてスポーン間隔を短くする
    if (elapsed_time <= M_REFRESH_RATE * 40) {
        m_spawn_interval = M_REFRESH_RATE * 7;
    }
    else if (elapsed_time <= M_REFRESH_RATE * 20) {
        m_spawn_interval = M_REFRESH_RATE * 6;
    }
    else if (elapsed_time <= M_REFRESH_RATE * 10) {
        m_spawn_interval = M_REFRESH_RATE * 5;
    }
    else
    {
        m_spawn_interval = M_REFRESH_RATE * 8;
    }

    // スポーン間隔カウント
    m_spawn_timer++;

    // スポーン間隔が指定数上回ったとき
    if (m_spawn_timer >= m_spawn_interval) {

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

    // マウス座標を取得
    int mouse_x, mouse_y;
    GetMousePoint(&mouse_x, &mouse_y);
    bool mouseDown = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;


    // ドラッグ開始判定
    if (!m_dragged_slime && mouseDown) {
        for (auto& slime : m_slimes) {
            if (!slime->IsDragging() && CheckCircleClick(slime->GetX(), slime->GetY(), 80)) {
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

            int cx = slime->GetX() + slime->GetWidth() / 2;
            int cy = slime->GetY() + slime->GetHeight() / 2;

            bool inLeft = m_left_area->IsInside(cx, cy);
            bool inRight = m_right_area->IsInside(cx, cy);

            // 青色ケース
            if (m_left_area->GetType() == slime->GetType()) {
                if (!inLeft && slime->GetCheckOutCase()) {
                    // 自動侵入 → 押し戻す＆方向反射
                    m_left_area->PushOut(*slime, true);
                    slime->ReflectDirection();

                }
                else {
                    m_left_area->PushOut(*slime, false);
                    slime->ReflectDirection();
                    if (m_left_area->CanContainMore()) {
                        m_left_area->AddSlime();
                    }
                    else {
                        if (slime->GetStateType() == EnemyState::NO_EXPLOSION) {
                            slime->SetAlive(false); // プールに返す
                            m_return_slime++;     // SCORE加算
                        }
                    }

                }
            }
            else {
                if (!inLeft && slime->GetCheckOutCase()) {
                    // 自動侵入 → 押し戻す＆方向反射
                    m_left_area->PushOut(*slime, true);
                    slime->ReflectDirection();
                }
                else {
                    // ゲームオーバー
                    m_phase = RESULT;

                }

            }

            // 赤色ケース
            if (m_right_area->GetType() == slime->GetType()) {

                if (!inRight && slime->GetCheckOutCase()) {
                    // 自動侵入 → 押し戻す＆方向反射
                    m_right_area->PushOut(*slime, true);
                    slime->ReflectDirection();
                }
                else {
                    m_right_area->PushOut(*slime, false);
                    slime->ReflectDirection();

                    if (m_right_area->CanContainMore()) {
                        m_right_area->AddSlime();
                    }
                    else {
                        if (slime->GetStateType() == EnemyState::NO_EXPLOSION) {
                            slime->SetAlive(false); // プールに返す
                            m_return_slime++;     // SCORE加算
                        }
                    }

                }
            }
            else {

                if (!inRight && slime->GetCheckOutCase()) {
                    // 自動侵入 → 押し戻す＆方向反射
                    m_right_area->PushOut(*slime, true);
                    slime->ReflectDirection();
                }
                else {
                    // ゲームオーバー
                    m_phase = RESULT;
                }

            }

        }
    }

    // 
    if (m_dragged_slime) {

        m_dragged_slime->DrugMove(mouse_x, mouse_y);

        // 左エリア・右エリアどちらかにいるかチェック
        if (m_dragged_slime->GetType() == m_left_area->GetType()) {
            m_dragged_slime->CheckInsideCase(m_left_area->GetX(), m_left_area->GetY(),
                m_left_area->GetW(), m_left_area->GetH());
        }

        if (m_dragged_slime->GetType() == m_right_area->GetType()) {
            m_dragged_slime->CheckInsideCase(m_right_area->GetX(), m_right_area->GetY(),
                m_right_area->GetW(), m_right_area->GetH());
        }

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

}

void InGame::TimeUpdate()
{
    // 残り時間
    elapsed_time--;

    // タイムアップ
    if (elapsed_time <= 0) {
        m_phase = RESULT;
    }
}

// スライムスポーン
void InGame::SpawnSlime() {
    int type = GetRand(1);
    int img = (type == 0) ? m_blue_image : m_red_image;

    int x, y;
    do {
        x = GetRand(1180);
        y = GetRand(620);
    } while (m_left_area->IsInside(x, y, 80, 80) || m_right_area->IsInside(x, y, 80, 80));

    auto s = m_pool.Acquire();
    s->Start(x, y, 80, 80, img, EnemyState::MOVE, type);
    m_slimes.push_back(s);
}

// 描画
void InGame::Render() {
    // 背景描画
    bg->SizeDraw();

    switch (m_phase)
    {
    case TITLE:

        DrawExtendGraph(0, 0, M_BG_SIZE_W, M_BG_SIZE_H, Load::Instance().GetTitleGrh(), true);
        DrawGraph(30, 200, Load::Instance().GetStartTexGrh(),true);

        break;
    case INGAME:

        // ケースの描画
        m_left_area->Draw();
        m_right_area->Draw();
        // スライムの描画
        for (auto& slime : m_slimes) {
            slime->Draw();
        }

        // 現在スコアの表示
        SetFontSize(M_FONTSIZE);
        DrawFormatString(30, 30, GetColor(0, 0, 0), "SCORE:%4d", m_score);
        // 残り時間の表示
        DrawFormatString(10, 10, GetColor(0, 0, 0), "残り時間:%2d", elapsed_time / M_REFRESH_RATE);

        break;
    case RESULT:

        // 終了
        DrawRotaGraph(650, 250, 2.0f, 0.0f,Load::Instance().GetEndGrh(), true);
        DrawRotaGraph(650, 600, 1.5f, 0.0f, Load::Instance().GetEndTextGrh(), true);

        // SCORE表示
        SetFontSize(50);
        DrawFormatString(500, 400, GetColor(0, 0, 0), "SCORE:%4d", m_score);

        break;

    default:
        break;
    }


}

