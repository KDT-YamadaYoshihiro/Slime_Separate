#pragma once
#include "ScreenBase.h"

class Result : public ScreenBase {
public:
	Result() = default;
	virtual ~Result() = default;
	// ������
	void Init() override;
	// �X�V
	void Update() override;
	// �`��
	void Render() override;
};