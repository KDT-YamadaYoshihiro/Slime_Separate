#pragma once
#include <memory>
#include "ScreenBase.h"

class ScreenManager {


	// �X�N���[���|�C���^�[
	std::shared_ptr<ScreenBase> m_scrPtr = nullptr;

	// window���[�h
	bool m_window_mode = true;

	// �V���O���g��
	// ������
	ScreenManager() = default;

	virtual ~ScreenManager() {};

public:

	ScreenManager(const ScreenManager&) = delete;
	ScreenManager& operator = (const ScreenManager&) = delete;
	static ScreenManager& Instance() {
		static ScreenManager instance;
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

};

template<typename T>
inline void ScreenManager::ChangeScreen()
{
	// �֐����E�N���X<�^>();
	m_scrPtr = std::make_shared<T>();

}
