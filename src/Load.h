#pragma once
#include "DxLib.h"

class Load {

	// 画像ハンドル
	int bg = -1;
	int red_slime = -1;
	int blue_slime = -1;

	// コンストラクタ
	// 初期化
	Load() {
		// 背景
		bg = LoadGraph("data/bg/bg.png");
		// 赤スライム
		red_slime = LoadGraph("data/enemy/red_slime.png");
		blue_slime = LoadGraph("data/enemy/blue_slime.png");
	};

public:

	// コピー禁止
	Load(const Load&) = delete;
	// 代入禁止
	Load& operator = (const Load&) = delete;
	// シングルトン
	static Load& Instance() {
		static Load instance;
		return instance;
	}

	// デストラクタ
	// メモリ開放
	virtual ~Load() {
		DeleteGraph(bg);
		DeleteGraph(red_slime);
		DeleteGraph(blue_slime);
	}

	// ゲッター
	int GetBgGrh() const { return bg; }
	int GetRedSlimeGrh() const { return red_slime; }
	int GetBlueSlimeGrh() const { return blue_slime; }

};