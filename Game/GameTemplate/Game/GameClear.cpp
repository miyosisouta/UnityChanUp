#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

GameClear::GameClear()
{
	//ゲームクリアの画像を読み込む。
	spriteRender.Init("Assets/sprite/gameclear2.DDS", 1920.0f, 1080.0f);

	//効果音を読み込む。
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/sound effect.wav");
}

GameClear::~GameClear()
{

}

void GameClear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA)) 
	{
		//効果音を再生する。
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(2);
		//ループさせないためfalseにする
		se->Play(false);
		//音量上げる
		se->SetVolume(3.5f);

		//タイトルオブジェクトを作る
		NewGO<Title>(0, "title");
		//自信を削除
		DeleteGO(this);
	}
}

void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
