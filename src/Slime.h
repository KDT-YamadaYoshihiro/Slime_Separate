#pragma once
#include "DxLib.h"
#include <memory>
#include "Case.h"

// ステート状態
enum class EnemyState {
    WAIT,
    MOVE,
    EXPLOSION,
    NO_EXPLOSION
};

// 移動方向
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
    // ステートタイプ
    EnemyState m_state_type;
    // 爆発判定
    bool m_explosion_flag;
    // 生存判定
    bool m_alive;
    // ドラッグ判定
    bool m_dragging;

    // 生存フレームの最大
    const int M_FRAME_MAX;
    // 移動量
    const int M_MOVE_SPEED;

    int m_move_direction;
    // 座標
    int m_pos_x;
    int m_pos_y;
    // サイズ
    int m_size_x;
    int m_size_y;
    // ハンドル
    int m_image_handle;
    // 残り生存フレームカウント
    int m_frame_count;
    // 跳ね管理フレーム
    int m_bounce_frame;
    int m_type; // 0:青,1:赤

    // 状態
    float m_dx = 0;
    float m_dy = 0;
    bool m_flipX = false;
    bool m_flipY = false;

public:
    // 初期化
    Slime();
    // スタート関数
    void Start(int pos_x, int pos_y, int size_x, int size_y, int image_handle, EnemyState state_type, int type);
    // 更新
    void Update();
    // 描画
    void Draw();
    // ドラッグ
    void DrugMove(int mouse_x, int mouse_y);
    // 座標更新
    void UpdatePosition();
    // バウンド移動
    void CheckBoundary();
    // 
    void ReflectDirection();
    // 
    DIRECTION GetDirectionFromVector(float dx, float dy);
    // フラグセット
    void SetExplosionFlag(bool flag) { m_explosion_flag = flag; }
    // ドラッグ判定のセットとゲット
    void SetDragging(bool flag) { m_dragging = flag; }
    bool IsDragging() const { return m_dragging; }
    // 生存判定のセットとゲット
    void SetAlive(bool flag) { m_alive = flag; }
    bool IsAlive() const { return m_alive; }
    // タイプの取得
    int GetType() const { return m_type; }
    // 座標のセットと取得
    void SetX(int arg_x) { m_pos_x = arg_x; }
    void SetY(int arg_y) { m_pos_y = arg_y; }
    int GetX() const { return m_pos_x; }
    int GetY() const { return m_pos_y; }
    // サイズの取得
    int GetWidth() const { return m_size_x; }
    int GetHeight() const { return m_size_y; }

private:
    // ステートタイプ別行動
    void StateType();
    // 移動処理
    void Move();
};