#pragma once
#include "DxLib.h"
#include <ctime>


// �Q�[�����[�v�N���X
class CGame {

	// window�T�C�Y
	const int M_WINDOW_W = 1280;
	const int M_WINDOW_H = 720;


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

	int GetWindowSizeW() const { return M_WINDOW_W; }
	int GetWindowSizeH() const { return M_WINDOW_H; }

};
