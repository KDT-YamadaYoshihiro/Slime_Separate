#pragma once
#include "ScreenBase.h"

class Ingame : public ScreenBase {
public:
	Ingame() = default;
	virtual ~Ingame() = default;
	// ‰Šú‰»
	void Init() override;
	// XV
	void Update() override;
	// •`‰æ
	void Render() override;
};