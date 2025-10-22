#pragma once
#include "ObjectPool.h"
#include "ScreenBase.h"
#include "DrawImage.h"
#include "Case.h"
#include "Slime.h"
#include <vector>
#include <memory>

class InGame : public ScreenBase {

private:

    // スライムオブジェクトプール
    ObjectPool<Slime> m_pool;
    // スライムベクター
    std::vector<std::shared_ptr<Slime>> m_slimes;
    // ドラッグしているスライム
    std::shared_ptr<Slime> m_dragged_slime = nullptr;

    // 背景
    std::shared_ptr<DrawImage> bg = nullptr;
    // ケースエリア
    std::shared_ptr<CaseArea> m_left_area = nullptr;
    std::shared_ptr<CaseArea> m_right_area = nullptr;
    
    static const int repursue = 60;

    // 青スライムの画像ハンドル
    int m_blue_image;
    // 赤スライムの画像ハンドル
    int m_red_image;
    
    int elapsed_time;

    // 経過時間
    int m_spawn_timer;
    // スポーン間隔
    int m_spawn_interval;
    // 最大同時出現数
    int m_max_slime;
    // 同時出現数
    int m_spawn_slime;
    // 現在のスコア
    int m_score;

public:
    // 初期化
    InGame();
    // 初期化
    void Init() override;
    // 更新
    void Update() override;
    // 描画
    void Render() override;

private:
    // スライムのスポーン
    void SpawnSlime();

};
