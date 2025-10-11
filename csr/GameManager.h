#pragma once
#include <memory>
#include "ScreenBase.h"

class GameManager {

	// スクリーンポインター
	std::shared_ptr<ScreenBase> m_scrPtr = nullptr;

	// windowモード
	bool m_window_mode = true;

	// windowサイズ
	const int M_WINDOW_W = 1280;
	const int M_WINDOW_H = 720;

	// シングルトン
	// 初期化
	GameManager() = default;

	virtual ~GameManager() {};

public:

	GameManager(const GameManager&) = delete;
	GameManager& operator = (const GameManager&) = delete;
	static GameManager& Instance() {
		static GameManager instance;
		return instance;
	}

	// 初期化
	void Init();

	// 更新処理
	void Update();

	// 描画処理
	void Render();

	// 終了
	void End();

	// 画面切り替えメソッド
	template<typename T>
	void ChangeScreen();

	bool GetWindowMode() const { return m_window_mode; }
	int GetWindowSizeW() const { return M_WINDOW_W; }
	int GetWindowSizeH() const { return M_WINDOW_H; }

};

template<typename T>
inline void GameManager::ChangeScreen()
{
	// 関数名・クラス<型>();
	scrPtr = std::make_shared<T>();

}
