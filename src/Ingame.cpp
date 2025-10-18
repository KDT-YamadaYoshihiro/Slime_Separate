#include "Ingame.h"
#include "Load.h"
#include "ScreenManager.h"
#include "Result.h"

Ingame::Ingame()
	:frame(3600)
{
	// 背景
	bg = std::make_shared<DrawImage>(0, 0, M_BG_SIZE_W, M_BG_SIZE_H, Load::Instance().GetBgGrh());
	// エネミー
	pool = std::make_shared<ObjectPool<Slime>>(2);

}

void Ingame::Init()
{
	// フレームカウント
	frame = 3600;

}

void Ingame::Update()
{
	
	

	if (End()) {
		ScreenManager::Instance().ChangeScreen<Result>();
	}

}

void Ingame::Render()
{
	bg->SizeDraw();
}

bool Ingame::End()
{

	frame--;

	if (frame < 0) {

		return true;

	}
	else {
		return false;
	}

}
