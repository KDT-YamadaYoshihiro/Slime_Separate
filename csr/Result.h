#pragma once
#include "ScreenBase.h"

class Result : public ScreenBase {
public:
	Result() = default;
	virtual ~Result() = default;
	// ‰Šú‰»
	void Init() override;
	// XV
	void Update() override;
	// •`‰æ
	void Render() override;
};