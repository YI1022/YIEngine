#pragma once
class AnimationClip;

class SkinModelRender : public IGameObject
{
private:
	Model m_model;								//モデル
	ModelInitData m_modelInitData;				//モデルの初期化情報
	Skeleton m_skeleton;						//スケルトン
	CharacterController m_charaCon;				//キャラクターコントローラー

	Vector3 m_position = Vector3::Zero;			//座標
	Vector3 m_scale = Vector3::One;				//サイズ
	Quaternion m_qRot = Quaternion::Identity;	//回転

public:
	SkinModelRender();
	~SkinModelRender();
	bool Start();
	void Update();

	void SetPosition(Vector3 pos) { m_position = pos; }
	void SetScale(Vector3 scale) { m_scale = scale; }
	void SetRotation(Quaternion rot) { m_qRot = rot; }
	void SetModel() { m_model.Init(m_modelInitData); }

	Vector3 GetPosition() { return m_position; }
	Vector3 GetScale() { return m_scale; }
	Quaternion GetRotation() { return m_qRot; }


	void Init(const char* modelFilePath);

};

