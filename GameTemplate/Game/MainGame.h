#pragma once

class SkinModelRender;

class MainGame : public IGameObject
{
private:
	SkinModelRender* m_Player1 = nullptr;
	SkinModelRender* m_BackGround = nullptr;

public:
	MainGame();
	~MainGame();
	bool Start();
	void Update();
};