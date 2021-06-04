#pragma once



/// <summary>
/// �\�����o�b�t�@
/// </summary>
class StructuredBuffer : public IShaderResource {
public:
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~StructuredBuffer();
	/// <summary>
	/// �\�����o�b�t�@���������B
	/// </summary>
	/// <param name="sizeOfElement">�G�������g�̃T�C�Y�B</param>
	/// <param name="numElement">�G�������g�̐��B</param>
	/// <param name="initData">�����f�[�^�B</param>
	void Init(int sizeOfElement, int numElement, void* initData);
	
	/// <summary>
	/// SRV�ɓo�^�B
	/// </summary>
	/// <param name="descriptorHandle"></param>
	void RegistShaderResourceView(D3D12_CPU_DESCRIPTOR_HANDLE descriptorHandle, int bufferNo) override;
	/// <summary>
	/// �\�����o�b�t�@�̓��e���X�V�B
	/// </summary>
	/// <param name="data"></param>
	void Update(void* data);
	/// <summary>
	/// ����������Ă��邩����B
	/// </summary>
	/// <returns></returns>
	bool IsInited() const
	{
		return m_isInited;
	}
	ID3D12Resource* GetD3DResoruce() ;
private:
	ID3D12Resource* m_buffersOnGPU[2] = {nullptr};
	void* m_buffersOnCPU[2] = { nullptr };		//CPU������A�N�Z�X�ł��邷��X�g���N�`���o�b�t�@�̃A�h���X�B
	int m_numElement = 0;				//�v�f���B
	int m_sizeOfElement = 0;			//�G�������g�̃T�C�Y�B
	bool m_isInited = false;			//�������ς݁H
};