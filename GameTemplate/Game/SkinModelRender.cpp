#include "stdafx.h"
#include "SkinModelRender.h"

SkinModelRender::SkinModelRender() 
{

}
SkinModelRender::~SkinModelRender()
{

}
bool SkinModelRender::Start()
{
	return true;
}
void SkinModelRender::Update()
{
	m_model.UpdateWorldMatrix(m_position, m_qRot, m_scale);
	auto& renderContext = g_graphicsEngine->GetRenderContext();
	m_model.Draw(renderContext);
}
void SkinModelRender::Init(const char* modelFilePath)
{
	m_modelInitData.m_tkmFilePath = modelFilePath;
	m_modelInitData.m_fxFilePath = "Assets/shader/model.fx";

	//‰Šú‰»î•ñ‚Åƒ‚ƒfƒ‹‚ğ‰Šú‰»‚·‚é
	m_model.Init(m_modelInitData);
}