#pragma once
#include "math.h"
#include "stdafx.h"

//ディレクションライトの構造体
struct DirectionLight
{
	Vector3 direction = Vector3::Zero;		//ライトの方向
	float pad = 0.0f;						//パディング
	Vector3 color = Vector3::Zero;			//ライトの色
};

//ポイントライトの構造体
struct PointLight
{
	Vector3 pointPos = Vector3::Zero;		//ポイントライトの位置
	float pad = 0.0f;						//パディング
	Vector3 color = Vector3::Zero;			//ライトの色
	float range = 0.0f;						//影響範囲
};

//スポットライトの構造体
struct SpotLight
{
	Vector3 spotPos = Vector3::Zero;		//スポットライトの位置
	float pad = 0.0f;						//パディング
	Vector3 color = Vector3::Zero;			//ライトの色
	float range = 0.0f;						//影響範囲
	Vector3 direction = Vector3::Zero;		//ライトの方向
	float angle = 0.0f;						//ライトの角度
};

//ライトをまとめるための構造体
struct Lights
{
	DirectionLight directionLight;			//ディレクションライト
	PointLight pointLight;					//ポイントライト
	SpotLight spotLight;					//スポットライト
	float pad = 0.0f;					
	Vector3 eyePos = Vector3::Zero;			//目の位置
	Vector3 ambientLight = Vector3::Zero;	//環境光
		
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

