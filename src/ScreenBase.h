#pragma once
#include "DrawImage.h"
#include <memory>

class ScreenBase {

protected:

	std::weak_ptr<DrawImage> bg;

public:
	// �I��
	virtual ~ScreenBase() = default;
	// ������
	virtual void Init() = 0;
	// �X�V
	virtual void Update() = 0;
	// �`��
	virtual void Render() = 0;
};