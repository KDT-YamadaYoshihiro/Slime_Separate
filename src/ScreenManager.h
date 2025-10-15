#pragma once
#include <memory>
#include "ScreenBase.h"

class ScreenManager {


	// スクリーンポインター
	std::shared_ptr<ScreenBase> m_scrPtr = nullptr;

	// windowモード
	bool m_window_mode = true;

	// シングルトン
	// 初期化
	ScreenManager() = default;

	virtual ~ScreenManager() {};

public:

	ScreenManager(const ScreenManager&) = delete;
	ScreenManager& operator = (const ScreenManager&) = delete;
	static ScreenManager& Instance() {
		static ScreenManager instance;
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

};

template<typename T>
inline void ScreenManager::ChangeScreen()
{
	// 関数名・クラス<型>();
	m_scrPtr = std::make_shared<T>();

}
