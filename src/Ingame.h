#pragma once
#include "ScreenBase.h"

class Ingame : public ScreenBase {
public:
	Ingame() = default;
	virtual ~Ingame() = default;
	// ������
	void Init() override;
	// �X�V
	void Update() override;
	// �`��
	void Render() override;
};