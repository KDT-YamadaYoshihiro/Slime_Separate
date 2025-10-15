#pragma once
#include "DxLib.h"

class Load {

	int bg = -1;

	// コンストラクタ
	// 初期化
	Load() {
		bg = LoadGraph("data/bg/bg.png");
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
	}

	int GetBgGrh() const { return bg; }



};