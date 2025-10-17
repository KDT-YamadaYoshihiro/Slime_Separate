#include "Ingame.h"
#include "Load.h"

Ingame::Ingame()
{
	// 背景
	bg = std::make_shared<DrawImage>(0, 0, M_BG_SIZE_W, M_BG_SIZE_H, Load::Instance().GetBgGrh());

	// エネミー


}

void Ingame::Init()
{
}

void Ingame::Update()
{
	
}

void Ingame::Render()
{
	bg->SizeDraw();
}
