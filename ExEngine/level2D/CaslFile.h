#pragma once
#include <list>
#include <vector>

/// <summary>
/// Casl�t�@�C���̃f�[�^�B
/// </summary>
struct CaslData
{
public:
	std::unique_ptr<char[]> name;			//���O�B
	std::unique_ptr<char[]> fileName;		//�t�@�C���̃p�X�B
	std::unique_ptr<char[]> ddsFileName;	//dds�t�@�C���B
	std::unique_ptr<char[]> ddsFilePath;	//dds�t�@�C���̃p�X�B
	Vector2 position;						//���W�B
	int width = 0;							//�����B
	int height = 0;							//�c���B
	int numberLayer = 0;					//���C���[�D��x�B
	Vector2 scale;							//�傫���B
};

/// <summary>
/// casl�t�@�C����ǂݍ��ށB
/// </summary>
class CaslFile
{
public:
	/// <summary>
	/// casl�t�@�C����ǂݍ��ށB
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X�B</param>
	void Load(const char* filePath);
	/// <summary>
	/// Casl�f�[�^�̐����擾�B
	/// </summary>
	/// <returns>Casl�f�[�^�̐��B</returns>
	const int GetNumCaslData() const
	{
		return m_caslDataList.size();
	}
	/// <summary>
	/// Casl�f�[�^���擾�B
	/// </summary>
	/// <param name="number">�i���o�[�B</param>
	/// <returns></returns>
	CaslData* GetCaslData(int number) const
	{
		return m_caslDataList[number].get();
	}
private:
	//1���������ǂݍ��ށA(,)��ǂݍ��ނ̂Ɏg���B
	/// <summary>
	/// 1���������ǂݍ��ށB�u , �v��u \n �v��ǂݍ��ނ̂Ɏg���B
	/// </summary>
	/// <param name="file">�t�@�C���B</param>
	void ReadOnlyOneCharacter(FILE* file) const;
	/// <summary>
	/// int�^��ǂݍ��ށB
	/// </summary>
	/// <param name="file">�t�@�C���B</param>
	/// <returns>int�^�̒l�B</returns>
	int ReadInteger(FILE* file) const;
	/// <summary>
	/// float�^��ǂݍ��ށB
	/// </summary>
	/// <param name="file">�t�@�C���B</param>
	/// <returns>float�^�̒l�B</returns>
	float ReadDecimal(FILE* file) const;

	std::vector<std::unique_ptr<CaslData>> m_caslDataList;		//Casl�f�[�^�B
};
