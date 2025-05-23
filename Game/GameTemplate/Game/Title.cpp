#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "Manual.h"

Title::Title() 
{
	//タイトル
	spriteRender.Init("Assets/sprite/Title1.DDS", 1920.0f, 1080.0f);

	//BGM読み込み
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/titlebgm.wav");
	//BGM再生
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);

	//効果音を読み込む。
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/sound effect.wav");
}

Title::~Title()
{
	//タイトルのBGMを削除する。
	DeleteGO(titleBGM);
}

void Title::Update()
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

		NewGO<Manual>(0, "manual");
		DeleteGO(this);  //Aボタンが押されたとき、タイトルが消え、説明書画像になる
	}
}

void Title::Render(RenderContext& rc)
{
	//描画
	spriteRender.Draw(rc);
}


