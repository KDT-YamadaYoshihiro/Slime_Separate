#include "Ingame.h"
#include "Load.h"
#include "ScreenManager.h"
#include "Result.h"

Ingame::Ingame()
	:frame(3600)
{
	// �w�i
	bg = std::make_shared<DrawImage>(0, 0, M_BG_SIZE_W, M_BG_SIZE_H, Load::Instance().GetBgGrh());
	// �G�l�~�[
	pool = std::make_shared<ObjectPool<Slime>>(2);

}

void Ingame::Init()
{
	// �t���[���J�E���g
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
