#pragma once

class Manager {



	bool window_mode = true;

	// �V���O���g��
	// ������
	Manager() = default;

	virtual ~Manager() {};

public:

	Manager(const Manager&) = delete;
	Manager& operator = (const Manager&) = delete;
	static Manager& Instance() {
		static Manager instance;
		return instance;
	}

	// ������
	void Init();

	// �X�V����
	void Update();

	// �`�揈��
	void Render();

	// ��ʐ؂�ւ����\�b�h
	template<typename T>
	void ChangeScreen();


	bool getWindowMode() const { return window_mode; }
};

template<typename T>
inline void Manager::ChangeScreen()
{

}
