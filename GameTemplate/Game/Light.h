#pragma once
#include "math.h"
#include "stdafx.h"

//�f�B���N�V�������C�g�̍\����
struct DirectionLight
{
	Vector3 direction = Vector3::Zero;		//���C�g�̕���
	float pad = 0.0f;						//�p�f�B���O
	Vector3 color = Vector3::Zero;			//���C�g�̐F
};

//�|�C���g���C�g�̍\����
struct PointLight
{
	Vector3 pointPos = Vector3::Zero;		//�|�C���g���C�g�̈ʒu
	float pad = 0.0f;						//�p�f�B���O
	Vector3 color = Vector3::Zero;			//���C�g�̐F
	float range = 0.0f;						//�e���͈�
};

//�X�|�b�g���C�g�̍\����
struct SpotLight
{
	Vector3 spotPos = Vector3::Zero;		//�X�|�b�g���C�g�̈ʒu
	float pad = 0.0f;						//�p�f�B���O
	Vector3 color = Vector3::Zero;			//���C�g�̐F
	float range = 0.0f;						//�e���͈�
	Vector3 direction = Vector3::Zero;		//���C�g�̕���
	float angle = 0.0f;						//���C�g�̊p�x
};

//���C�g���܂Ƃ߂邽�߂̍\����
struct Lights
{
	DirectionLight directionLight;			//�f�B���N�V�������C�g
	PointLight pointLight;					//�|�C���g���C�g
	SpotLight spotLight;					//�X�|�b�g���C�g
	float pad = 0.0f;					
	Vector3 eyePos = Vector3::Zero;			//�ڂ̈ʒu
	Vector3 ambientLight = Vector3::Zero;	//����
		
};

class Light : public IGameObject
{
private:
	Lights m_light;

public:
	Light();
	~Light();
	bool Start();
	void Update();

	Lights& GetLight() { return m_light; }
	Lights* GetLightAddress() { return &m_light; }

	Vector3 GetDirctionLight() { return m_light.directionLight.direction; }
	Vector3 GetPointLightPos() { return m_light.pointLight.pointPos; }
	Vector3 GetSpotLightPos() { return m_light.spotLight.spotPos; }
};

