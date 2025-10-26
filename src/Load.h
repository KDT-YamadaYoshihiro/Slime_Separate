#pragma once
#include "DxLib.h"

class Load {

	// 画像ハンドル
	int bg = -1;
	int title = -1;
	int start_text = -1;
	int end = -1;
	int end_text = -1;
	int red_slime = -1;
	int blue_slime = -1;

	// コンストラクタ
	// 初期化
	Load() {
		// 背景
		bg = LoadGraph("data/bg/bg.jpg");
		// タイトル
		title = LoadGraph("data/title/title.png");
		// スタートテキスト
		start_text = LoadGraph("data/title/start.png");
		// 終了テキスト
		end = LoadGraph("data/result/end.png");
		end_text = LoadGraph("data/result/end_text.png");
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
		DeleteGraph(title);
		DeleteGraph(start_text);
		DeleteGraph(end);
		DeleteGraph(end_text);
		DeleteGraph(red_slime);
		DeleteGraph(blue_slime);
	}

	// ゲッター
	int GetBgGrh() const { return bg; }
	int GetTitleGrh() const { return title; }
	int GetStartTexGrh() const { return start_text; }
	int GetEndGrh() const { return end; }
	int GetEndTextGrh() const { return end_text; }
	int GetRedSlimeGrh() const { return red_slime; }
	int GetBlueSlimeGrh() const { return blue_slime; }

};