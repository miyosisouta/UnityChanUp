#include "stdafx.h"
#include "star.h"
#include "Player.h"

star::star()
{
	//☆のモデルを読み込む。
	modelRender.Init("Assets/modelData/star.tkm");
	player = FindGO<Player>("player");
}

star::~star()
{

}

void star::Update()
{
	//移動処理。
	Move();

	//回転処理。
	Rotation();

	//絵描きさんの更新処理。
	modelRender.Update();

	//プレイヤーから☆に向かうベクトルを計算。
	Vector3 diff = player->position - position;

	//ベクトルの長さが120.0fより小さかったら。
	if (diff.Length() <= 120.0f)
	{
		player->starCount += 1;

		//自身を削除する。
		DeleteGO(this);
	}
}

void star::Move()
{

	//絵描きさんに座標を教える
	modelRender.SetPosition(position);
}

void star::Rotation()
{
	//回転を加算
	rotation.AddRotationDegY(2.0f);

	//絵描きに回転を教える
	modelRender.SetRotation(rotation);
}

void star::Render(RenderContext& rc)
{
	//☆を描画
	modelRender.Draw(rc);
}
