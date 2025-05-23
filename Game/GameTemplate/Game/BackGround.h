#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	bool Start();
	void Update();
	//描画関数
	void Render(RenderContext& rc);

	Vector3 m_position = Vector3::Zero;
	Vector3 m_scale = Vector3::One;
	Quaternion m_rotation = Quaternion::Identity;
	//モデルレンダー・定義
	ModelRender modelRender;
	//世界に当たり判定を与える
	PhysicsStaticObject physicsStaticObject;
};

