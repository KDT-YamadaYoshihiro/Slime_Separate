#include "Bomb.h"
#include "mouse.h"
#include "DxLib.h"

// �R���X�g���N�^
Bomb::Bomb( int image_handle)
	: m_state_type(EnemyState::WAIT),
	m_explosion_flag(false),
	M_FRAME_MAX(300),
	M_MOVE_SPEED(2),
	m_move_direction(0),
	m_pos_x(0),
	 m_pos_y(0),
	 m_size_x(0),
	 m_size_y(0),
	 m_image_handle(image_handle),
	 m_frame_count(0)
{
}

// �X�V����
void Bomb::Update()
{
	


}

// �`�揈��
void Bomb::Draw(unsigned int arg_Color)
{
	//DrawExtendGraph(m_pos_x, m_pos_y, m_pos_x + m_size_x, m_pos_y + m_size_y, m_image_handle, TRUE);

	// �~��`��
	static const int RADIUS = 20;
	DrawCircle(m_pos_x, m_pos_y, RADIUS, arg_Color, true);

}

// �X�^�[�g�֐�
void Bomb::Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type)
{
	m_pos_x = pos_x;
	m_pos_y = pos_y;
	m_size_x = size_x;
	m_size_y = size_y;
	m_image_handle = image_handle;
	m_state_type = state_type;
	m_frame_count = 0;

}

// stateType�̓��e
void Bomb::StateType()
{
	switch (m_state_type)
	{
	case EnemyState::WAIT:

		// �ҋ@����

		break;

	case EnemyState::MOVE:

		// �ړ�����
		Move();

		// �t���[���J�E���g
		m_frame_count++;

		// ��萔�o�߂�����A�{�̃A�j���[�V������ύX����i�������O�j
		if (m_frame_count) {

		}

		// �J�E���g������𒴂������Ԃ�ς���
		if(m_frame_count <= M_FRAME_MAX)
		{
			m_state_type = EnemyState::EXPLOSION;
		}

		// �d���������������Ƃ�
		if (m_explosion_flag)
		{
			m_state_type = EnemyState::NO_EXPLOSION;
		}

		break;

	case EnemyState::EXPLOSION:

		// ��������

		// �A�j���[�V�����Đ�

		break;

	case EnemyState::NO_EXPLOSION:

		// �G�l�~�[�{�̂̃C���X�g�ύX�B

		// ���[�u��ԑ��s

		break;

	default:
		break;
	}
}

// �ʏ�ړ�
void Bomb::Move()
{



}

// �h���b�N�ړ�
void Bomb::DrugMove(int arg_mousu_x, int arg_mousu_y)
{

	if()


}


