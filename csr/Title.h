#pragma once
#include "ScreenBase.h"

class Title : public ScreenBase {

public:
	Title() = default;
	virtual ~Title() = default;
	// ������
	void Init() override;
	// �X�V
	void Update() override;
	// �`��
	void Render() override;
};