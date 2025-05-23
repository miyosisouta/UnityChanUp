#include "stdafx.h"
#include "Game.h"
#include "BackGround.h"
#include "Player.h"
#include "GameCamera.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include "star.h"
#include "GameClear.h"
#include "Manual.h"
#include "GameOver.h"

Game::Game() 
{

	//オブジェクト作成
	background = NewGO<BackGround>(0);
	player = NewGO<Player>(0,"player");
	gamecamera = NewGO<GameCamera>(0,"gameCamera");

    //Starのオブジェクト作成
    star* star1 = NewGO<star>(0, "star");
    star1->position = { 1564.0f,3600.0f,900.0f };
    star1->firstPosition = star1->position;

    //ゲーム中BGM読み込み
    g_soundEngine->ResistWaveFileBank(1, "Assets/sound/gamebgm1.wav");
    //ゲーム中のBGM再生
    gameBGM = NewGO<SoundSource>(0);
    gameBGM->Init(1);
    gameBGM->Play(true);

    //空のオブジェクトを作成する。
    m_skyCube = NewGO<SkyCube>(0, "skycube");

    g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 0.5f);
    g_renderingEngine->SetCascadeNearAreaRates(0.01f, 0.1f, 0.5f);

}
Game::~Game() 
{
    //プレイヤー削除
    DeleteGO(player);

    //ゲームカメラ削除
    DeleteGO(gamecamera);

    //ゲーム中のBGM削除
    DeleteGO(gameBGM);

    //背景削除
    DeleteGO(background);
}

void Game::Update()
{
    //制限時間の表示
    wchar_t wcount[256];
    swprintf_s(wcount, 256, L"%d", int(m_gameTimer));
    //表示するテキストを設定。
    fontRender.SetText(wcount);
    //フォントの位置。
    fontRender.SetPosition(Vector3(-100.0f,500.0f, 0.0f));
    //フォントの大きさ
    fontRender.SetScale(2.0f);
    //フォントの色
    fontRender.SetColor({ 1.0f,0.0f,0.0f,1.0f });

    m_gameTimer -= g_gameTime->GetFrameDeltaTime();

    if (m_gameTimer < 0)
    {
        NewGO<GameOver>(0, "gameover");
        DeleteGO(this);
    }


    if (player->position.y < -1000.0f) {
        NewGO<GameOver>(0, "gameover");
        DeleteGO(this);
    }

    if (player->starCount == 1) {
       
       NewGO<GameClear>(0, "gameclear");
       DeleteGO(this);       
    }
}

void Game::Render(RenderContext& rc)
{
    fontRender.Draw(rc);
}

