#pragma once
#include <algorithm>
#include "DxLib.h"

class Slime;

class CaseArea {
	int x, y, w, h;
	int targetType; // 0:青, 1:赤
	unsigned int color;
	int slimeCount = 0; // 中にいるスライム数

public:

	// 初期化
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

	// 描画
	void Draw() const {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(x, y, x + w, y + h, color, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	}

	// 範囲判定
	bool IsInside(int cx, int cy) const {
		return (cx >= x && cx <= x + w && cy >= y && cy <= y + h);
	}
	bool IsInside(int px, int py, int pw, int ph) const {
		return (px < x + w && px + pw > x && py < y + h && py + ph > y);
	}

	// スライムを押し戻す
	void PushOut(Slime& slime, bool putin) const;

	// ケース内が20未満かチェック
	bool CanContainMore() const
	{
		return slimeCount < 20;
	}
	// ケース内のスライムのカウントを増やす
	void AddSlime()
	{
		++slimeCount;
	}
	// ケース内のスライムの数を減らす
	void RemoveSlime() 
	{
		if (slimeCount > 0){
			--slimeCount;
		}
	}
	// カウントをリセット
	void ResetCount()
	{
		slimeCount = 0;
	}
	// カウントを取得
	int GetCount() const
	{
		return slimeCount;
	}
	// カラータイプの取得
	int GetType() const
	{
		return targetType;
	}
	// 座標の取得
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetW() const { return w; }
	int GetH() const { return h; }

};