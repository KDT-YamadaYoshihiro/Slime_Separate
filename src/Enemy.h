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
    // 状態管理
    EnemyState m_state_type;

    // 爆発フラグ
    bool m_explosion_flag;

    // アニメーションフレーム
    int m_frame_count;
    const int M_FRAME_MAX;

    // 移動速度
    const int M_MOVE_SPEED;
    int m_move_direction; // 0:右, 1:左 など

    // 位置・サイズ
    int m_pos_x, m_pos_y;
    int m_size_x, m_size_y;

    // 画像ハンドル
    int m_image_handle;

public:
    Slime();

    // 更新処理
    void Update();

    // 描画
    void Draw(unsigned int arg_Color = GetColor(255, 255, 255));

    // 初期化
    void Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type = EnemyState::WAIT);

    // 状態処理
    void StateType();

    // 通常移動
    void Move();

    // ドラッグ移動
    void DragMove();

    // 爆発処理
    void Explode();

    // 仕分け成功
    void SetExplosionFlag(bool flag) { m_explosion_flag = flag; }

    // ゲッター
    int GetX() const { return m_pos_x; }
    int GetY() const { return m_pos_y; }
    int GetSizeX() const { return m_size_x; }
    int GetSizeY() const { return m_size_y; }
    EnemyState GetState() const { return m_state_type; }
};
