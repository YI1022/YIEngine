#include "stdafx.h"
#include "MainGame.h"
#include "SkinModelRender.h"

MainGame::MainGame()
{
	m_Player1 = NewGO<SkinModelRender>(0);
	m_Player1->Init("Assets/modelData/unityChan.tkm");

	m_BackGround = NewGO<SkinModelRender>(0);
	m_BackGround->Init("Assets/modelData/bg/bg.tkm");
}
MainGame::~MainGame()
{
	DeleteGO(m_Player1);
	DeleteGO(m_BackGround);
}
bool MainGame::Start()
{
	return true;
}
void MainGame::Update()
{

}