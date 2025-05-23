#pragma once
class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();

	//更新
	void Update();

	//描画処理。
	void Render(RenderContext& rc);

	//メンバ変数。
	SpriteRender spriteRender; //スプライトレンダ―。

};
