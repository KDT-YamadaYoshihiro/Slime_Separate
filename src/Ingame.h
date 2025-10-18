#pragma once
#include "ScreenBase.h"
#include "ObjectPool.h"
#include "Enemy.h"

class Ingame : public ScreenBase {

	// 2種類のエネミー
	std::shared_ptr<ObjectPool<Slime>> pool;

	// 残り時間
	int frame;


public:
	Ingame();
	virtual ~Ingame() = default;
	// 初期化
	void Init() override;
	// 更新
	void Update() override;
	// 描画
	void Render() override;

	// フレームカウント終了
	bool End();

};