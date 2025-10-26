#pragma once
#include "ScreenBase.h"


class Title : public ScreenBase {

	int blend;

public:
	Title() = default;
	virtual ~Title() = default;
	// 初期化
	void Init() override;
	// 更新
	void Update() override;
	// 描画
	void Render() override;

	// ブレンド更新
	void BlendUpdate();
};