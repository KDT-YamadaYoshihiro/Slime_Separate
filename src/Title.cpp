#include "Title.h"
#include "ScreenManager.h"
#include "Ingame.h"
#include "Load.h"

void Title::Init()
{
	bg = std::make_shared<DrawImage>(0, 0, 1280, 720, Load::Instance().GetBgGrh());

	blend = 0;
}

void Title::Update()
{
	BlendUpdate();

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) { // ¶ƒNƒŠƒbƒN‚ª‰Ÿ‚³‚ê‚½ê‡
		ScreenManager::Instance().ChangeScreen<InGame>();
	}
}

void Title::Render()
{
	// ”wŒi
	bg->SizeDraw();
	// •¶š
	DrawExtendGraph(0, 0, 1280, 740, Load::Instance().GetTitleGrh(), true);

	// 
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, blend);
	DrawGraph(30, 200, Load::Instance().GetStartTexGrh(),true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Title::BlendUpdate()
{

	int add_blend = 10;

	blend += add_blend;

	if (add_blend >= 0 && blend >= 255) {
		add_blend *= -1;
	}
	if (add_blend <= 0 && blend <= 0) {
		add_blend *= -1;
	}
}
