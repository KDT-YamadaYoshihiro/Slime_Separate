#pragma once
#include "DxLib.h"
#include <ctime>


// �Q�[�����[�v�N���X
class CGame {

	const int WINDOW_W = 800;
	const int WINDOW_H = 400;

	// �R���X�g���N�^
	CGame() = default;
	// �f�X�g���N�^
	virtual ~CGame() = default;


public:

	CGame(const CGame&) = delete;
	CGame& operator = (const CGame&) = delete;
	static CGame& Instance() {
		static CGame instance;
		return instance;
	}

	// ������
	bool Init();
	// ���[�v����
	void Run();
	// �X�V
	void Update();
	// �`��
	void Render();
	// �I��
	void End();

	int getWindowW() const { return WINDOW_W; }
	int getWindowH() const { return WINDOW_H; }
};
