#pragma once
#include "DxLib.h"
#include <ctime>


// ゲームループクラス
class CGame {

	const int WINDOW_W = 800;
	const int WINDOW_H = 400;

	// コンストラクタ
	CGame() = default;
	// デストラクタ
	virtual ~CGame() = default;


public:

	CGame(const CGame&) = delete;
	CGame& operator = (const CGame&) = delete;
	static CGame& Instance() {
		static CGame instance;
		return instance;
	}

	// 初期化
	bool Init();
	// ループ処理
	void Run();
	// 更新
	void Update();
	// 描画
	void Render();
	// 終了
	void End();

	int getWindowW() const { return WINDOW_W; }
	int getWindowH() const { return WINDOW_H; }
};
