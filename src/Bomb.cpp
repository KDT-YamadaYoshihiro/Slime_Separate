#include "Bomb.h"
#include "mouse.h"
#include "DxLib.h"

// コンストラクタ
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

// 更新処理
void Bomb::Update()
{
	


}

// 描画処理
void Bomb::Draw(unsigned int arg_Color)
{
	//DrawExtendGraph(m_pos_x, m_pos_y, m_pos_x + m_size_x, m_pos_y + m_size_y, m_image_handle, TRUE);

	// 円を描画
	static const int RADIUS = 20;
	DrawCircle(m_pos_x, m_pos_y, RADIUS, arg_Color, true);

}

// スタート関数
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

// stateTypeの内容
void Bomb::StateType()
{
	switch (m_state_type)
	{
	case EnemyState::WAIT:

		// 待機処理

		break;

	case EnemyState::MOVE:

		// 移動処理
		Move();

		// フレームカウント
		m_frame_count++;

		// 一定数経過したら、本体アニメーションを変更する（爆発直前）
		if (m_frame_count) {

		}

		// カウントが上限を超えたら状態を変える
		if(m_frame_count <= M_FRAME_MAX)
		{
			m_state_type = EnemyState::EXPLOSION;
		}

		// 仕分けが成功したとき
		if (m_explosion_flag)
		{
			m_state_type = EnemyState::NO_EXPLOSION;
		}

		break;

	case EnemyState::EXPLOSION:

		// 爆発処理

		// アニメーション再生

		break;

	case EnemyState::NO_EXPLOSION:

		// エネミー本体のイラスト変更。

		// ムーブ状態続行

		break;

	default:
		break;
	}
}

// 通常移動
void Bomb::Move()
{



}

// ドラック移動
void Bomb::DrugMove(int arg_mousu_x, int arg_mousu_y)
{

	if()


}


