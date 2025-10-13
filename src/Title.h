#pragma once
#include "ScreenBase.h"

class Title : public ScreenBase {

public:
	Title() = default;
	virtual ~Title() = default;
	// ‰Šú‰»
	void Init() override;
	// XV
	void Update() override;
	// •`‰æ
	void Render() override;
};