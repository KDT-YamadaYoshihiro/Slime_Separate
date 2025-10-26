#include "Case.h"
#include "Slime.h"

void CaseArea::PushOut(Slime& slime, bool putin) const
{

	// スライムの座標とサイズ取得
	int px = slime.GetX();
	int py = slime.GetY();
	int pw = slime.GetWidth();
	int ph = slime.GetHeight();

	// 範囲外なら処理しない
	if (!IsInside(px, py, pw, ph))
	{
		return;
	}
	
	// ケース外に出ている場合だけ押し返す
	if (putin) {
		slime.PushOutFromRect(x, y, w, h);
	}
	else {
		slime.CheckBoundary(x, y, w, h);
	}
}

