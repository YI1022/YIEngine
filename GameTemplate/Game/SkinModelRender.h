#pragma once
class AnimationClip;

class SkinModelRender : public IGameObject
{
private:
	Model m_model;								//���f��
	ModelInitData m_modelInitData;				//���f���̏��������
	Skeleton m_skeleton;						//�X�P���g��
	CharacterController m_charaCon;				//�L�����N�^�[�R���g���[���[

	Vector3 m_position = Vector3::Zero;			//���W
	Vector3 m_scale = Vector3::One;				//�T�C�Y
	Quaternion m_qRot = Quaternion::Identity;	//��]

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

