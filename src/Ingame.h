#pragma once
#include "ScreenBase.h"

class Ingame : public ScreenBase {


public:
	Ingame();
	virtual ~Ingame() = default;
	// ������
	void Init() override;
	// �X�V
	void Update() override;
	// �`��
	void Render() override;
};