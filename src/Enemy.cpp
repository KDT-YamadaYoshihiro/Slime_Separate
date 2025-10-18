#include "Enemy.h"

Slime::Slime()
    : m_state_type(EnemyState::WAIT),
    m_explosion_flag(false),
    M_FRAME_MAX(300),
    M_MOVE_SPEED(2),
    m_move_direction(0),
    m_pos_x(0),
    m_pos_y(0),
    m_size_x(50),
    m_size_y(50),
    m_image_handle(-1),
    m_frame_count(0)
{
}

void Slime::Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type)
{
    m_pos_x = pos_x;
    m_pos_y = pos_y;
    m_size_x = size_x;
    m_size_y = size_y;
    m_image_handle = image_handle;
    m_state_type = state_type;
    m_frame_count = 0;
    m_explosion_flag = false;
}

void Slime::Update()
{
    StateType();
}

void Slime::StateType()
{
    switch (m_state_type)
    {
    case EnemyState::WAIT:
        // 待機中は特に移動なし
        break;

    case EnemyState::MOVE:
        Move();
        m_frame_count++;
        if (m_frame_count >= M_FRAME_MAX)
            m_state_type = EnemyState::EXPLOSION;

        if (m_explosion_flag)
            m_state_type = EnemyState::NO_EXPLOSION;
        break;

    case EnemyState::EXPLOSION:
        Explode();
        break;

    case EnemyState::NO_EXPLOSION:
        Move();
        break;

    default:
        break;
    }
}

void Slime::Move()
{
    // サンプル: 右に移動して、端で反転
    if (m_move_direction == 0)
        m_pos_x += M_MOVE_SPEED;
    else
        m_pos_x -= M_MOVE_SPEED;

    if (m_pos_x + m_size_x >= 800) m_move_direction = 1;
    if (m_pos_x <= 0) m_move_direction = 0;
}

void Slime::DragMove()
{
    int mouse_x, mouse_y;
    GetMousePoint(&mouse_x, &mouse_y);
    m_pos_x = mouse_x - m_size_x / 2;
    m_pos_y = mouse_y - m_size_y / 2;
}

void Slime::Explode()
{



    // フラグで終了
    m_explosion_flag = true;
}

void Slime::Draw(unsigned int arg_Color)
{
    if (m_image_handle >= 0)
        DrawExtendGraph(m_pos_x, m_pos_y, m_pos_x + m_size_x, m_pos_y + m_size_y, m_image_handle, TRUE);
}
