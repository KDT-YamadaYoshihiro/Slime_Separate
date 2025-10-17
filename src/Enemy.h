#pragma once
#include "enum.h"

class Bomb {

	// stateType
	EnemyState m_state_type;

	// �����t���O
	bool m_explosion_flag;

	// �t���[���ő吔
	const int M_FRAME_MAX;	

	// �ړ����x
	const int M_MOVE_SPEED;

	// �ړ�����
	int m_move_direction;

	// ���W
	int m_pos_x;
	int m_pos_y;

	// �T�C�Y
	int m_size_x;
	int m_size_y;

	// �摜�n���h��
	int m_image_handle; 

	// �t���[���J�E���g
	int m_frame_count;

public:

	// �R���X�g���N�^
	Bomb(int image_handle);

	// �X�V����
	void Update();

	// �`�揈��
	void Draw(unsigned int arg_color);

	// �X�^�[�g�֐�
	void Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type);

	// stateType�̓��e
	void StateType();

	// �ړ�����
	void Move();

	// �h���b�O�ړ�
	void DrugMove(int arg_mousu_x, int arg_mousu_y);

	// �����t���O�̎擾
	bool GetExplosionFlag() { return m_explosion_flag; }
	// �����t���O�̐ݒ�
	void SetExplosionFlag(bool explosion_flag) { m_explosion_flag = explosion_flag; }

};