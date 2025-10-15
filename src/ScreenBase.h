#pragma once
#include "DrawImage.h"
#include <vector>
#include <string>
#include <memory>

class ScreenBase {


protected:

	std::shared_ptr<DrawImage> bg;
	const int M_BG_SIZE_W = 1280;
	const int M_BG_SIZE_H = 720;

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