#pragma once
#include "ObjectPool.h"
#include "ScreenBase.h"
#include "DrawImage.h"
#include "Case.h"
#include "Slime.h"
#include <vector>
#include <memory>

enum PHASE {
    TITLE,
    INGAME,
    RESULT
};

class InGame : public ScreenBase {

private:

    PHASE m_phase;
    // スライムオブジェクトプール
    ObjectPool<Slime> m_pool;
    // スライムベクター
    std::vector<std::shared_ptr<Slime>> m_slimes;
    // ドラッグしているスライム
    std::shared_ptr<Slime> m_dragged_slime = nullptr;

    //// 背景
    //std::shared_ptr<DrawImage> bg = nullptr;
    // ケースエリア
    std::shared_ptr<CaseArea> m_left_area = nullptr;
    std::shared_ptr<CaseArea> m_right_area = nullptr;
    
    // リフレッシュレート
    static const int M_REFRESH_RATE = 60;
    // SCORE
    static const int M_SCORE = 100;
    // フォントサイズ
    static const int M_FONTSIZE = 30;

    // 青スライムの画像ハンドル
    int m_blue_image;
    // 赤スライムの画像ハンドル
    int m_red_image;
    
    // 残り時間
    int elapsed_time;

    // 経過時間
    int m_spawn_timer;
    // スポーン間隔
    int m_spawn_interval;
    // 最大同時出現数
    int m_max_slime;
    // 同時出現数
    int m_spawn_slime;
    // ケース内からプールに返還された数
    int m_return_slime;
    // 現在のスコア
    int m_score;

    

public:
    // 初期化
    InGame();
    // 初期化
    void Init() override;
    // 更新
    void Update() override;
    // スライムの更新
    void SlimeUpdate();
    // タイム更新
    void TimeUpdate();
    // 描画
    void Render() override;

private:
    // スライムのスポーン
    void SpawnSlime();

};
