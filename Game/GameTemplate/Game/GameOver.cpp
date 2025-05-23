#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"

GameOver::GameOver()
{
	//ゲームクリアの画像を読み込む。
	spriteRender.Init("Assets/sprite/gameover.DDS", 1920.0f, 1080.0f);
}

GameOver::~GameOver()
{
}

void GameOver::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//タイトルオブジェクトを作る
		NewGO<Title>(0, "title");
		//自信を削除
		DeleteGO(this);
	}
}

void GameOver::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
