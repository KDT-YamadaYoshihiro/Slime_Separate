#pragma once
#include "DrawImage.h"
#include <memory>

class ScreenBase {

protected:

	std::weak_ptr<DrawImage> bg;

public:
	// I—¹
	virtual ~ScreenBase() = default;
	// ‰Šú‰»
	virtual void Init() = 0;
	// XV
	virtual void Update() = 0;
	// •`‰æ
	virtual void Render() = 0;
};