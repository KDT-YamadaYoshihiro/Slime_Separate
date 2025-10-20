#pragma once
#include <algorithm>
#include "DxLib.h"

class CaseArea {
	int x, y, w, h;
	int targetType; // 0:青, 1:赤
	unsigned int color;
	int slimeCount = 0; // 中にいるスライム数

public:
	CaseArea(int _x, int _y, int _w, int _h, int _type)
		: x(_x), y(_y), w(_w), h(_h), targetType(_type)
	{
		if (targetType == 0) {
			color = GetColor(0, 0, 255);
		}
		else {
			color = GetColor(255, 0, 0);
		}
	}

	void Draw() const {
		DrawBox(x, y, x + w, y + h, color, TRUE);
	}

	bool IsInside(int px, int py, int pw, int ph) const {
		return (px < x + w && px + pw > x && py < y + h && py + ph > y);
	}

	void PushOut(float px, float py, float pw, float ph) const {
		if (!IsInside((int)px, (int)py, (int)pw, (int)ph)) return;

		float overlapLeft = (px + pw) - x;
		float overlapRight = (x + w) - px;
		float overlapTop = (py + ph) - y;
		float overlapBottom = (y + h) - py;

		// std::minを使う
		float min1 = (std::min)(overlapLeft, overlapRight);   // ← ()で囲むのがポイント
		float min2 = (std::min)(overlapTop, overlapBottom);
		float minOverlap = (std::min)(min1, min2);

		if (minOverlap == overlapLeft) {
			px -= overlapLeft;
		}
		else if (minOverlap == overlapRight) {
			px += overlapRight;
		}
		else if (minOverlap == overlapTop) {
			py -= overlapTop;
		}
		else {
			py += overlapBottom;
		}
	}

	bool IsInside(int cx, int cy) const {
		return (cx >= x && cx <= x + w &&
			cy >= y && cy <= y + h);
	}

	bool CanContainMore() const {
		return slimeCount < 20;
	}

	void AddSlime() { ++slimeCount; }
	void RemoveSlime() { if (slimeCount > 0) --slimeCount; }
	void ResetCount() { slimeCount = 0; }
	int GetCount() const { return slimeCount; }

	int GetType() const { return targetType; }
};