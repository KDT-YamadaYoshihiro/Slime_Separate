#include "Slime.h"
#include <cstdlib>
#include <cmath>
#include <map>

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
    m_type(0)
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
        if (m_explosion_flag) m_state_type = EnemyState::NO_EXPLOSION;
        else if (m_frame_count >= M_FRAME_MAX) m_state_type = EnemyState::EXPLOSION;
        break;
    case EnemyState::EXPLOSION: m_alive = false; break;
    case EnemyState::NO_EXPLOSION: m_alive = false; break;
    }
}

// 移動処理
void Slime::Move() {
    UpdatePosition();
    CheckBoundary();
    ReflectDirection();
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

// 行動制限（画面内に）
void Slime::CheckBoundary() {
    m_flipX = false;
    m_flipY = false;

    // x方向制限
    if (m_pos_x < 0) {
        m_pos_x = 0;
        m_flipX = true;
    }
    else if (m_pos_x + m_size_x > 1280) {
        m_pos_x = 1280 - m_size_x;
        m_flipX = true;
    }

    // y方向制限
    if (m_pos_y < 0) {
        m_pos_y = 0;
        m_flipY = true;
    }
    else if (m_pos_y + m_size_y > 720) {
        m_pos_y = 720 - m_size_y;
        m_flipY = true;
    }
}

// 壁に当たった時
void Slime::ReflectDirection() {
    if (m_flipX) m_dx *= -1;
    if (m_flipY) m_dy *= -1;
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
