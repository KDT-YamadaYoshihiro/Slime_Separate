#pragma once

class RegionBox {
	int m_pos_x;    // X���W
	int m_pos_y;    // Y���W
	int m_size_x;   // ��
	int m_size_y;   // ����

public:

	// ������
	RegionBox()
		: m_pos_x(0), m_pos_y(0), m_size_x(0), m_size_y(0)
	{
	}
	RegionBox(int pos_x, int pos_y, int size_x, int size_y)
		: m_pos_x(pos_x), m_pos_y(pos_y), m_size_x(size_x), m_size_y(size_y)
	{
	}

	// �f�X�g���N�^
	~RegionBox() {}

	// �����蔻��
	bool CheckHit(int pos_x, int pos_y) {
		if (pos_x >= m_pos_x && pos_x <= m_pos_x + m_size_x &&
			pos_y >= m_pos_y && pos_y <= m_pos_y + m_size_y) {
			return true;
		}
		return false;
	}

	// ���W�A�T�C�Y�Z�b�g
	void SetRegion(int pos_x, int pos_y, int size_x, int size_y) {
		m_pos_x = pos_x;
		m_pos_y = pos_y;
		m_size_x = size_x;
		m_size_y = size_y;
	}
	// X���W�擾
	int GetPosX() { return m_pos_x; }
	// Y���W�擾
	int GetPosY() { return m_pos_y; }
	// ���擾
	int GetSizeX() { return m_size_x; }
	// �����擾
	int GetSizeY() { return m_size_y; }

}
