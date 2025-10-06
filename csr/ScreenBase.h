#pragma once

class ScreenBase {
public:
	virtual ~ScreenBase() = default;
	// ‰Šú‰»
	virtual void Init() = 0;
	// XV
	virtual void Update() = 0;
	// •`‰æ
	virtual void Render() = 0;
};