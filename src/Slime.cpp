#include "Slime.h"
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>

// 初期化
Slime::Slime()
    : m_state_type(EnemyState::WAIT),
    m_explosion_flag(false),
    m_alive(false),
    m_dragging(false),
    M_FRAME_MAX(1200),
    M_MOVE_SPEED(2),
    m_move_direction(0),
    m_pos_x(0),
    m_pos_y(0),
    m_size_x(0),
    m_size_y(0),
    m_image_handle(-1),
    m_frame_count(0),
    m_bounce_frame(0),
    m_type(0),
    m_check_outcase(true)
{
}

// スタート関数
void Slime::Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type, int type) {
    m_pos_x = pos_x;
    m_pos_y = pos_y;
    m_size_x = size_x;
    m_size_y = size_y;
    m_image_handle = image_handle;
    m_state_type = state_type;
    m_frame_count = 0;
    m_bounce_frame = 0;
    m_explosion_flag = false;
    m_alive = true;
    m_type = type;
    m_dragging = false;
    m_move_direction = GetRand(7);
}

// 更新処理
void Slime::Update() {
    if (!m_alive || m_dragging) return;
    StateType();
}

// 描画
void Slime::Draw() {
    if (!m_alive) return;
    float bounceOffset = std::sin(m_bounce_frame * 0.2f) * 5.0f;
    int drawY = static_cast<int>(m_pos_y - bounceOffset);
    DrawExtendGraph(m_pos_x, drawY, m_pos_x + m_size_x, drawY + m_size_y, m_image_handle, TRUE);
    m_bounce_frame = (m_bounce_frame + 1) % 360;
}

// ステータスタイプ別行動処理
void Slime::StateType() {
    switch (m_state_type) {
    case EnemyState::WAIT: break;
    case EnemyState::MOVE:
        
        Move();

        m_frame_count++;

        if (!m_check_outcase)
        {
            m_state_type = EnemyState::NO_EXPLOSION;
        }
        if (m_frame_count >= M_FRAME_MAX) {
             m_state_type = EnemyState::EXPLOSION;
        }

        break;
    case EnemyState::EXPLOSION:
        m_alive = false;
        break;
    case EnemyState::NO_EXPLOSION:
        
        Move();

        break;
    }
}

// 移動処理
void Slime::Move() {
    UpdatePosition();
    CheckBoundary(0,0,1280,720);
}

// 移動方向
void Slime::UpdatePosition() {
    // 移動ベクトルテーブル
    static const std::pair<float, float> directionTable[] = {
        {0, 1},   // DOWN
        {0, -1},  // UP
        {-1, 0},  // LEFT
        {1, 0},   // RIGHT
        {1, 1},   // RIGHT_DOWN
        {1, -1},  // RIGHT_UP
        {-1, 1},  // LEFT_DOWN
        {-1, -1}  // LEFT_UP
    };

    m_dx = directionTable[m_move_direction].first;
    m_dy = directionTable[m_move_direction].second;

    // 斜め補正
    if (m_dx != 0 && m_dy != 0) {
        const float diag = 1.0f / std::sqrt(2.0f);
        m_dx *= diag;
        m_dy *= diag;
    }

    m_pos_x += m_dx * M_MOVE_SPEED;
    m_pos_y += m_dy * M_MOVE_SPEED;
}

void Slime::CheckInsideCase(float caseX, float caseY, float caseW, float caseH)
{
    // スライムの中心座標
    float cx = m_pos_x + m_size_x / 2;
    float cy = m_pos_y + m_size_y / 2;

    // 内部判定
    bool inside =
        (cx >= caseX) &&
        (cx <= caseX + caseW) &&
        (cy >= caseY) &&
        (cy <= caseY + caseH);

    // 内なら false、外なら true に設定
    m_check_outcase = !inside;
}

// 行動制限（画面内に）
void Slime::CheckBoundary(int arg_posX, int arg_posY, int arg_sizeW, int arg_sizeH) {
    
    m_flip_x = false;
    m_flip_y = false;

    int right = arg_posX + arg_sizeW;
    int buttom = arg_posY + arg_sizeH;

    // x方向制限
    if (m_pos_x < arg_posX) {
        m_pos_x = arg_posX;
        m_dx *= -1;
    }
    else if (m_pos_x + m_size_x > right) {
        m_pos_x = right - m_size_x;
        m_dx *= -1;
    }

    // y方向制限
    if (m_pos_y < arg_posY) {
        m_pos_y = arg_posY;
        m_dy *= -1;
    }
    else if (m_pos_y + m_size_y > buttom) {
        m_pos_y = buttom - m_size_y;
        m_dy *= -1;
    }

    // ベクトルから方向を再判定
    m_move_direction = GetDirectionFromVector(m_dx, m_dy);

}

// 行動制限（矩形内の侵入拒否）
void Slime::PushOutFromRect(float rectX, float rectY, float rectW, float rectH)
{
    // スライムの矩形
    float sx1 = m_pos_x;
    float sy1 = m_pos_y;
    float sx2 = m_pos_x + m_size_x;
    float sy2 = m_pos_y + m_size_y;

    // 判定対象の矩形
    float bx1 = rectX;
    float by1 = rectY;
    float bx2 = rectX + rectW;
    float by2 = rectY + rectH;

    // 重なり量を計算
    float overlapX = min(sx2, bx2) - max(sx1, bx1);
    float overlapY = min(sy2, by2) - max(sy1, by1);

    // 重なっていない場合は終了
    if (overlapX <= 0 || overlapY <= 0) return;

    // 最も浅い方向に押し出し＋反射
    if (overlapX < overlapY) {
        // 左または右から侵入
        if (m_pos_x < bx1) { // 左から侵入
            m_pos_x -= overlapX;
            m_dx *= -1;
        }
        else { // 右から侵入
            m_pos_x += overlapX;
            m_dx *= -1;
        }
    }
    else {
        // 上または下から侵入
        if (m_pos_y < by1) { // 上から侵入
            m_pos_y -= overlapY;
            m_dy *= -1;
        }
        else { // 下から侵入
            m_pos_y += overlapY;
            m_dy *= -1;
        }
    }

    // ベクトルから方向を再判定
    m_move_direction = GetDirectionFromVector(m_dx, m_dy);
}

// 壁に当たった時
void Slime::ReflectDirection() {
    if (m_flip_x) 
    {
        m_dx *= -1;
    }
    if (m_flip_y)
    {
        m_dy *= -1;
    }
    m_move_direction = GetDirectionFromVector(m_dx, m_dy);
}

// ベクトルから方向を再判定
DIRECTION Slime::GetDirectionFromVector(float dx, float dy)
{
    int sx = (dx > 0) - (dx < 0); // -1, 0, 1
    int sy = (dy > 0) - (dy < 0); // -1, 0, 1

    static const std::map<std::pair<int, int>, DIRECTION> dirTable = {
        {{0, 1}, DOWN}, {{0, -1}, UP}, {{-1, 0}, LEFT}, {{1, 0}, RIGHT},
        {{1, 1}, RIGHT_DOWN}, {{1, -1}, RIGHT_UP},
        {{-1, 1}, LEFT_DOWN}, {{-1, -1}, LEFT_UP}
    };

    auto it = dirTable.find({ sx, sy });
    return (it != dirTable.end()) ? it->second : DOWN;
}

// ドラッグ移動
void Slime::DrugMove(int mouse_x, int mouse_y) {
    m_pos_x = mouse_x - m_size_x / 2;
    m_pos_y = mouse_y - m_size_y / 2;
}
