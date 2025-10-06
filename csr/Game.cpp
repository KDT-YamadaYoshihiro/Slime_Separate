#include "Game.h"
#include "Manager.h"


// ����������
bool CGame::Init()
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(Manager::Instance().getWindowMode());
	SetGraphMode(getWindowW(), getWindowH(), 32);
	
	if (Manager::Instance().getWindowMode() == TRUE)
	{
		SetWindowSize(getWindowW(), getWindowH());
	}
	
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("bomb_separate");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	Manager::Instance().Init();

}
// ���[�v����
void CGame::Run()
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//	���t���b�V�����[�g��ݒ肷�邽�߂̏���
		clock_t check_fps = clock() + CLOCKS_PER_SEC / 60;

		clsDx();
		ClearDrawScreen();

		this->Update();
		this->Render();

		//	���t���b�V�����[�g�����ɂȂ�܂ő҂���
		while (clock() < check_fps) {}

		ScreenFlip();
	}

}
// �X�V����
void CGame::Update()
{
	Manager::Instance().Update();
}

// �`�揈��
void CGame::Render()
{
	Manager::Instance().Render();
}

// �I������
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