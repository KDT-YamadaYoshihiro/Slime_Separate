#pragma once
#include "DxLib.h"

class DrawImage {

	// 座標
	int m_pos_x;
	int m_pos_y;
	// 画像サイズ
	int m_size_x;
	int m_size_y;
	// 画像ハンドル
	int m_handle;

public:

	// 初期化
	DrawImage()
		:m_pos_x(0),m_pos_y(0),m_size_x(0), m_size_y(0),m_handle(-1)
	{
	}

	// 初期化座標指定
	DrawImage(int arg_pos_x, int arg_pos_y)
		:m_pos_x(arg_pos_x), m_pos_y(arg_pos_y), m_handle(-1) 
	{
	}

	// 初期化座標、画像指定
	DrawImage(int arg_pos_x, int arg_pos_y, int arg_handle)
		:m_pos_x(arg_pos_x), m_pos_y(arg_pos_y), m_handle(arg_handle)
	{
	}

	// 初期化座標、サイズ、画像指定
	DrawImage(int arg_pos_x, int arg_pos_y, int arg_size_x, int arg_size_y, int arg_handle)
	:m_pos_x(arg_pos_x), m_pos_y(arg_pos_y), m_size_x(arg_size_x),m_size_y(arg_size_y), m_handle(arg_handle)
	{
	}

	// 描画
	void Draw() 
	{
		DrawGraph(m_pos_x, m_pos_y, m_handle, true);
	};

	// サイズ指定描画
	void SizeDraw() {
		DrawExtendGraph(m_pos_x, m_pos_y, m_size_x, m_size_y, m_handle, true);
	}

	// 座標セット
	void SetPos(int arg_pos_x, int arg_pos_y) {
		m_pos_x = arg_pos_x;
		m_pos_y = arg_pos_y;
	}

	// ハンドルセット
	void SetHandle(int arg_handle) { m_handle = arg_handle; }


};