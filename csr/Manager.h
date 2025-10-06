#pragma once

class Manager {



	bool window_mode = true;

	// シングルトン
	// 初期化
	Manager() = default;

	virtual ~Manager() {};

public:

	Manager(const Manager&) = delete;
	Manager& operator = (const Manager&) = delete;
	static Manager& Instance() {
		static Manager instance;
		return instance;
	}

	// 初期化
	void Init();

	// 更新処理
	void Update();

	// 描画処理
	void Render();

	// 画面切り替えメソッド
	template<typename T>
	void ChangeScreen();


	bool getWindowMode() const { return window_mode; }
};

template<typename T>
inline void Manager::ChangeScreen()
{

}
