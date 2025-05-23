#pragma once
#include "sound/SoundSource.h"
#include "Level3DRender/LevelRender.h"

class Player;
class BackGround;
class GameCamera;
class Manual;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Render(RenderContext& rc);

	Player* player;
	BackGround* background;
	GameCamera* gamecamera;
	SoundSource* gameBGM;
	FontRender fontRender;
	float m_gameTimer = 120.0f;
	SkyCube*   m_skyCube = nullptr;	   //ãÛÅB

private:
	Vector3 m_pos;
};

