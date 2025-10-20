#pragma once
#include "DxLib.h"
#include <memory>
#include "Case.h"

enum class EnemyState {
    WAIT,
    MOVE,
    EXPLOSION,
    NO_EXPLOSION
};

enum DIRECTION {
    DOWN,
    UP,
    LEFT,
    RIGHT,
    RIGHT_DOWN,
    RIGHT_UP,
    LEFT_DOWN,
    LEFT_UP,
    DIR_MAX
};

class Slime {
private:
    EnemyState m_state_type;
    bool m_explosion_flag;
    bool m_alive;
    bool m_dragging;

    const int M_FRAME_MAX;
    const int M_MOVE_SPEED;

    int m_move_direction;
    int m_pos_x;
    int m_pos_y;
    int m_size_x;
    int m_size_y;
    int m_image_handle;
    int m_frame_count;
    int m_bounce_frame;
    int m_type; // 0:ê¬,1:ê‘

public:
    Slime();
    void Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type, int type);
    void Update();
    void Draw();
    void DrugMove(int mouse_x, int mouse_y);

    void SetExplosionFlag(bool flag) { m_explosion_flag = flag; }
    void SetDragging(bool flag) { m_dragging = flag; }
    bool IsDragging() const { return m_dragging; }
    void SetAlive(bool flag) { m_alive = flag; }

    bool IsAlive() const { return m_alive; }
    int GetType() const { return m_type; }
    int GetX() const { return m_pos_x; }
    int GetY() const { return m_pos_y; }
    int GetWidth() const { return m_size_x; }
    int GetHeight() const { return m_size_y; }

private:
    void StateType();
    void Move();
};