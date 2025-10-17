#pragma once
#include "enum.h"

class Bomb {

	// stateType
	EnemyState m_state_type;

	// 爆発フラグ
	bool m_explosion_flag;

	// フレーム最大数
	const int M_FRAME_MAX;	

	// 移動速度
	const int M_MOVE_SPEED;

	// 移動方向
	int m_move_direction;

	// 座標
	int m_pos_x;
	int m_pos_y;

	// サイズ
	int m_size_x;
	int m_size_y;

	// 画像ハンドル
	int m_image_handle; 

	// フレームカウント
	int m_frame_count;

public:

	// コンストラクタ
	Bomb(int image_handle);

	// 更新処理
	void Update();

	// 描画処理
	void Draw(unsigned int arg_color);

	// スタート関数
	void Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type);

	// stateTypeの内容
	void StateType();

	// 移動処理
	void Move();

	// ドラッグ移動
	void DrugMove(int arg_mousu_x, int arg_mousu_y);

	// 爆発フラグの取得
	bool GetExplosionFlag() { return m_explosion_flag; }
	// 爆発フラグの設定
	void SetExplosionFlag(bool explosion_flag) { m_explosion_flag = explosion_flag; }

};