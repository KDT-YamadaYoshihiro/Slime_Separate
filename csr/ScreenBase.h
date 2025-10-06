#pragma once

class ScreenBase {
public:
	virtual ~ScreenBase() = default;
	// ������
	virtual void Init() = 0;
	// �X�V
	virtual void Update() = 0;
	// �`��
	virtual void Render() = 0;
};