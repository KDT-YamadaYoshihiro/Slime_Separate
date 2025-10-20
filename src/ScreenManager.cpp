#include "ScreenManager.h"
#include "Ingame.h"

void ScreenManager::Init()
{
	ChangeScreen<InGame>();
	m_scrPtr->Init();
}

void ScreenManager::Update()
{
	m_scrPtr->Update();
}

void ScreenManager::Render()
{
	m_scrPtr->Render();
}

void ScreenManager::End()
{

}
