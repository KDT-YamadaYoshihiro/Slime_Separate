#include "Slime.h"
#include <cstdlib>
#include <cmath>

Slime::Slime()
    : m_state_type(EnemyState::WAIT),
    m_explosion_flag(false),
    m_alive(false),
    m_dragging(false),
    M_FRAME_MAX(300),
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

void Slime::Update() {
    if (!m_alive || m_dragging) return;
    StateType();
}

void Slime::Draw() {
    if (!m_alive) return;
    float bounceOffset = std::sin(m_bounce_frame * 0.2f) * 5.0f;
    int drawY = static_cast<int>(m_pos_y - bounceOffset);
    DrawExtendGraph(m_pos_x, drawY, m_pos_x + m_size_x, drawY + m_size_y, m_image_handle, TRUE);
    m_bounce_frame = (m_bounce_frame + 1) % 360;
}

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

void Slime::Move() {
    switch (m_move_direction) {
    case DOWN: m_pos_y += M_MOVE_SPEED; break;
    case UP: m_pos_y -= M_MOVE_SPEED; break;
    case LEFT: m_pos_x -= M_MOVE_SPEED; break;
    case RIGHT: m_pos_x += M_MOVE_SPEED; break;
    case RIGHT_DOWN: m_pos_x += M_MOVE_SPEED; m_pos_y += M_MOVE_SPEED; break;
    case RIGHT_UP: m_pos_x += M_MOVE_SPEED; m_pos_y -= M_MOVE_SPEED; break;
    case LEFT_DOWN: m_pos_x -= M_MOVE_SPEED; m_pos_y += M_MOVE_SPEED; break;
    case LEFT_UP: m_pos_x -= M_MOVE_SPEED; m_pos_y -= M_MOVE_SPEED; break;
    }
    // ‰æ–Ê’[”½“]
    if (m_pos_x < 0 || m_pos_x + m_size_x > 1280) m_move_direction = (m_move_direction + 2) % DIR_MAX;
    if (m_pos_y < 0 || m_pos_y + m_size_y > 720) m_move_direction = (m_move_direction + 4) % DIR_MAX;
}

void Slime::DrugMove(int mouse_x, int mouse_y) {
    m_pos_x = mouse_x - m_size_x / 2;
    m_pos_y = mouse_y - m_size_y / 2;
}
