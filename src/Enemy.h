#pragma once
#include "DxLib.h"

enum class EnemyState {
    WAIT,
    MOVE,
    EXPLOSION,
    NO_EXPLOSION
};

class Slime
{
private:
    // ��ԊǗ�
    EnemyState m_state_type;

    // �����t���O
    bool m_explosion_flag;

    // �A�j���[�V�����t���[��
    int m_frame_count;
    const int M_FRAME_MAX;

    // �ړ����x
    const int M_MOVE_SPEED;
    int m_move_direction; // 0:�E, 1:�� �Ȃ�

    // �ʒu�E�T�C�Y
    int m_pos_x, m_pos_y;
    int m_size_x, m_size_y;

    // �摜�n���h��
    int m_image_handle;

public:
    Slime();

    // �X�V����
    void Update();

    // �`��
    void Draw(unsigned int arg_Color = GetColor(255, 255, 255));

    // ������
    void Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type = EnemyState::WAIT);

    // ��ԏ���
    void StateType();

    // �ʏ�ړ�
    void Move();

    // �h���b�O�ړ�
    void DragMove();

    // ��������
    void Explode();

    // �d��������
    void SetExplosionFlag(bool flag) { m_explosion_flag = flag; }

    // �Q�b�^�[
    int GetX() const { return m_pos_x; }
    int GetY() const { return m_pos_y; }
    int GetSizeX() const { return m_size_x; }
    int GetSizeY() const { return m_size_y; }
    EnemyState GetState() const { return m_state_type; }
};
