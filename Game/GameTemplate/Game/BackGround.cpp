#include "stdafx.h"
#include "BackGround.h"
#include "Player.h"

BackGround::BackGround()
{
	

}

BackGround::~BackGround()
{

}

bool BackGround::Start()
{
	modelRender.Init("Assets/modelData/background.tkm");
	//PhysicsStaticObject‚Ì‰Šú‰»
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	return true;
}

void BackGround::Update()
{
	modelRender.SetTRS(m_position, m_rotation, m_scale);
	modelRender.Update();
}

void BackGround::Render(RenderContext& rc)
{
	//ƒ‚ƒfƒ‹‚ğ•`‰æ
	modelRender.Draw(rc);
}
