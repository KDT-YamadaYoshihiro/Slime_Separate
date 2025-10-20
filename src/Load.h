#pragma once
#include "DxLib.h"

class Load {

	// �摜�n���h��
	int bg = -1;
	int red_slime = -1;
	int blue_slime = -1;

	// �R���X�g���N�^
	// ������
	Load() {
		// �w�i
		bg = LoadGraph("data/bg/bg.png");
		// �ԃX���C��
		red_slime = LoadGraph("data/enemy/red_slime.png");
		blue_slime = LoadGraph("data/enemy/blue_slime.png");
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
		DeleteGraph(red_slime);
		DeleteGraph(blue_slime);
	}

	// �Q�b�^�[
	int GetBgGrh() const { return bg; }
	int GetRedSlimeGrh() const { return red_slime; }
	int GetBlueSlimeGrh() const { return blue_slime; }

};