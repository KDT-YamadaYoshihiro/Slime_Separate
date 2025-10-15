#pragma once
#include "ScreenBase.h"

class Ingame : public ScreenBase {


public:
	Ingame();
	virtual ~Ingame() = default;
	// ‰Šú‰»
	void Init() override;
	// XV
	void Update() override;
	// •`‰æ
	void Render() override;
};