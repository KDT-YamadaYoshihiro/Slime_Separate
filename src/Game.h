#pragma once
#include "DxLib.h"
#include <ctime>


// ゲームループクラス
class CGame {

	// windowサイズ
	const int M_WINDOW_W = 1280;
	const int M_WINDOW_H = 720;


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

	int GetWindowSizeW() const { return M_WINDOW_W; }
	int GetWindowSizeH() const { return M_WINDOW_H; }

};
