#pragma once
#include <memory>
#include "ScreenBase.h"

class GameManager {

	// �X�N���[���|�C���^�[
	std::shared_ptr<ScreenBase> m_scrPtr = nullptr;

	// window���[�h
	bool m_window_mode = true;

	// window�T�C�Y
	const int M_WINDOW_W = 1280;
	const int M_WINDOW_H = 720;

	// �V���O���g��
	// ������
	GameManager() = default;

	virtual ~GameManager() {};

public:

	GameManager(const GameManager&) = delete;
	GameManager& operator = (const GameManager&) = delete;
	static GameManager& Instance() {
		static GameManager instance;
		return instance;
	}

	// ������
	void Init();

	// �X�V����
	void Update();

	// �`�揈��
	void Render();

	// �I��
	void End();

	// ��ʐ؂�ւ����\�b�h
	template<typename T>
	void ChangeScreen();

	bool GetWindowMode() const { return m_window_mode; }
	int GetWindowSizeW() const { return M_WINDOW_W; }
	int GetWindowSizeH() const { return M_WINDOW_H; }

};

template<typename T>
inline void GameManager::ChangeScreen()
{
	// �֐����E�N���X<�^>();
	scrPtr = std::make_shared<T>();

}
