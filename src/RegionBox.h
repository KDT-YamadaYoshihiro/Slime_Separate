#pragma once

class RegionBox {
	int m_pos_x;    // X座標
	int m_pos_y;    // Y座標
	int m_size_x;   // 幅
	int m_size_y;   // 高さ

public:

	// 初期化
	RegionBox()
		: m_pos_x(0), m_pos_y(0), m_size_x(0), m_size_y(0)
	{
	}
	RegionBox(int pos_x, int pos_y, int size_x, int size_y)
		: m_pos_x(pos_x), m_pos_y(pos_y), m_size_x(size_x), m_size_y(size_y)
	{
	}

	// デストラクタ
	~RegionBox() {}

	// 当たり判定
	bool CheckHit(int pos_x, int pos_y) {
		if (pos_x >= m_pos_x && pos_x <= m_pos_x + m_size_x &&
			pos_y >= m_pos_y && pos_y <= m_pos_y + m_size_y) {
			return true;
		}
		return false;
	}

	// 座標、サイズセット
	void SetRegion(int pos_x, int pos_y, int size_x, int size_y) {
		m_pos_x = pos_x;
		m_pos_y = pos_y;
		m_size_x = size_x;
		m_size_y = size_y;
	}
	// X座標取得
	int GetPosX() { return m_pos_x; }
	// Y座標取得
	int GetPosY() { return m_pos_y; }
	// 幅取得
	int GetSizeX() { return m_size_x; }
	// 高さ取得
	int GetSizeY() { return m_size_y; }

}
