#include "stdafx.h"
#include "manual.h"
#include "title.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/soundSource.h"

Manual::Manual()
{
	//説明書画像
	spriteRender.Init("Assets/sprite/manual.DDS", 1920.0f, 1080.0f);

	//効果音を読み込む。
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/sound effect.wav");
}

Manual::~Manual()
{

}

void Manual::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		
		//交換を再生する。
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(2);
		//ループさせないためfalseにする
		se->Play(false);
		//音量上げる
		se->SetVolume(3.5f);

		NewGO<Game>(0, "game");
		DeleteGO(this); //Aボタンを押すと、説明書画面が消え、ゲームが始める
	}
}

void Manual::Render(RenderContext& rc)
{
	//描画
	spriteRender.Draw(rc);
}

