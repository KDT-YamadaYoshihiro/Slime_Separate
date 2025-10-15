#include "Game.h"
#include "ScreenManager.h"


// 初期化処理
bool CGame::Init()
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(ScreenManager::Instance().GetWindowMode());
	SetGraphMode(M_WINDOW_W, M_WINDOW_H, 32);
	
	if (ScreenManager::Instance().GetWindowMode() == TRUE)
	{
		SetWindowSize(M_WINDOW_W, M_WINDOW_H);
	}
	
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("bomb_separate");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	ScreenManager::Instance().Init();

}
// ループ処理
void CGame::Run()
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//	リフレッシュレートを設定するための処理
		clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;

		clsDx();
		ClearDrawScreen();

		this->Update();
		this->Render();

		//	リフレッシュレートが一定になるまで待つ処理
		while (clock() < check_fps) {}

		ScreenFlip();
	}

}
// 更新処理
void CGame::Update()
{
	ScreenManager::Instance().Update();
}

// 描画処理
void CGame::Render()
{
	ScreenManager::Instance().Render();
}

// 終了処理
void CGame::End()
{
	DxLib_End();
}
// 
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	CGame::Instance().Init();
	CGame::Instance().Run();
	CGame::Instance().End();

	return 0;
}