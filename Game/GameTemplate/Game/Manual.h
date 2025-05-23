#pragma once

#include "sound/SoundSource.h"
class Manual : public IGameObject
{
public:
    Manual();
    ~Manual();
    //描画関数。
    void Render(RenderContext& rc);
    //更新
    void Update();
    //スプライトレンダ―。
    SpriteRender spriteRender;
    SoundSource* titleBGM;
};

