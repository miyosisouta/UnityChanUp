#pragma once
#include "sound/SoundSource.h"
class Title : public IGameObject
{
public:
    Title();
    ~Title();
    //描画関数。
    void Render(RenderContext& rc);
    //更新
    void Update();
   
    //スプライトレンダ―。
    SpriteRender spriteRender;
    SoundSource* titleBGM;

    ////ステート画像切り替え
   //void ChangeState(int chan);
    //int ChangeState = 0;
};

