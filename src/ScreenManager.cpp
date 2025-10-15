#include "ScreenManager.h"
#include "Ingame.h"

void ScreenManager::Init()
{
	ChangeScreen<Ingame>();
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
