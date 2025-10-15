#pragma once
#include "DxLib.h"

class Load {

	int bg = -1;

	// �R���X�g���N�^
	// ������
	Load() {
		bg = LoadGraph("data/bg/bg.png");
	};

public:

	// �R�s�[�֎~
	Load(const Load&) = delete;
	// ����֎~
	Load& operator = (const Load&) = delete;
	// �V���O���g��
	static Load& Instance() {
		static Load instance;
		return instance;
	}

	// �f�X�g���N�^
	// �������J��
	virtual ~Load() {
		DeleteGraph(bg);
	}

	int GetBgGrh() const { return bg; }



};