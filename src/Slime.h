#pragma once
#include "DxLib.h"
#include <memory>
#include "Case.h"

// �X�e�[�g���
enum class EnemyState {
    WAIT,
    MOVE,
    EXPLOSION,
    NO_EXPLOSION
};

// �ړ�����
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
    // �X�e�[�g�^�C�v
    EnemyState m_state_type;
    // ��������
    bool m_explosion_flag;
    // ��������
    bool m_alive;
    // �h���b�O����
    bool m_dragging;

    // �����t���[���̍ő�
    const int M_FRAME_MAX;
    // �ړ���
    const int M_MOVE_SPEED;

    int m_move_direction;
    // ���W
    int m_pos_x;
    int m_pos_y;
    // �T�C�Y
    int m_size_x;
    int m_size_y;
    // �n���h��
    int m_image_handle;
    // �c�萶���t���[���J�E���g
    int m_frame_count;
    // ���ˊǗ��t���[��
    int m_bounce_frame;
    int m_type; // 0:��,1:��

    // ���
    float m_dx = 0;
    float m_dy = 0;
    bool m_flipX = false;
    bool m_flipY = false;

public:
    // ������
    Slime();
    // �X�^�[�g�֐�
    void Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type, int type);
    // �X�V
    void Update();
    // �`��
    void Draw();
    // �h���b�O
    void DrugMove(int mouse_x, int mouse_y);
    // ���W�X�V
    void UpdatePosition();
    // �o�E���h�ړ�
    void CheckBoundary();
    // 
    void ReflectDirection();
    // 
    DIRECTION GetDirectionFromVector(float dx, float dy);
    // �t���O�Z�b�g
    void SetExplosionFlag(bool flag) { m_explosion_flag = flag; }
    // �h���b�O����̃Z�b�g�ƃQ�b�g
    void SetDragging(bool flag) { m_dragging = flag; }
    bool IsDragging() const { return m_dragging; }
    // ��������̃Z�b�g�ƃQ�b�g
    void SetAlive(bool flag) { m_alive = flag; }
    bool IsAlive() const { return m_alive; }
    // �^�C�v�̎擾
    int GetType() const { return m_type; }
    // ���W�̃Z�b�g�Ǝ擾
    void SetX(int arg_x) { m_pos_x = arg_x; }
    void SetY(int arg_y) { m_pos_y = arg_y; }
    int GetX() const { return m_pos_x; }
    int GetY() const { return m_pos_y; }
    // �T�C�Y�̎擾
    int GetWidth() const { return m_size_x; }
    int GetHeight() const { return m_size_y; }

private:
    // �X�e�[�g�^�C�v�ʍs��
    void StateType();
    // �ړ�����
    void Move();
};