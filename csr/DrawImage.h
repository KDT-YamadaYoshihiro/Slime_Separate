#pragma once
#include "DxLib.h"

class DrawImage {

	// ���W
	int m_pos_x;
	int m_pos_y;
	// �摜�T�C�Y
	int m_size_x;
	int m_size_y;
	// �摜�n���h��
	int m_handle;

public:

	// ������
	DrawImage()
		:m_pos_x(0),m_pos_y(0),m_size_x(0), m_size_y(0),m_handle(-1)
	{
	}

	// ���������W�w��
	DrawImage(int arg_pos_x, int arg_pos_y)
		:m_pos_x(arg_pos_x), m_pos_y(arg_pos_y), m_handle(-1) 
	{
	}

	// ���������W�A�摜�w��
	DrawImage(int arg_pos_x, int arg_pos_y, int arg_handle)
		:m_pos_x(arg_pos_x), m_pos_y(arg_pos_y), m_handle(arg_handle)
	{
	}

	// ���������W�A�T�C�Y�A�摜�w��
	DrawImage(int arg_pos_x, int arg_pos_y, int arg_size_x, int arg_size_y, int arg_handle)
	:m_pos_x(arg_pos_x), m_pos_y(arg_pos_y), m_size_x(arg_size_x),m_size_y(arg_size_y), m_handle(arg_handle)
	{
	}

	// �`��
	void Draw() 
	{
		DrawGraph(m_pos_x, m_pos_y, m_handle, true);
	};

	// �T�C�Y�w��`��
	void SizeDraw() {
		DrawExtendGraph(m_pos_x, m_pos_y, m_size_x, m_size_y, m_handle, true);
	}

	// ���W�Z�b�g
	void SetPos(int arg_pos_x, int arg_pos_y) {
		m_pos_x = arg_pos_x;
		m_pos_y = arg_pos_y;
	}

	// �n���h���Z�b�g
	void SetHandle(int arg_handle) { m_handle = arg_handle; }


};