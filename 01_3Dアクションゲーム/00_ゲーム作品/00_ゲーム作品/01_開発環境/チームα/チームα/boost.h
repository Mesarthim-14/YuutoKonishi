#ifndef _BOOST_H_
#define _BOOST_H_
//=============================================================================
//
// �u�[�X�^�[�̏��� [boost.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=========================================================================
// �C���N���[�h
//=========================================================================
#include "model.h"

//=========================================================================
// �}�N����`
//=========================================================================
#define BOOST_SIZE_X		(1.0f)		// �傫��
#define BOOST_SIZE_Y		(1.0f)		// �傫��
#define BOOST_SIZE_Z		(1.0f)		// �傫��
#define BOOST_LIFE			(15)		// �u�[�X�g�̃��C�t
#define MAX_BOOST			(2)			// �u�[�X�g�̐�
#define MAX_LASER_TEXTURE	(1)			// �e�N�X�`���̐�

//=========================================================================
// �u�[�X�^�[�N���X
//=========================================================================
class CBoost :public CModel
{
public:
	CBoost();		// �R���X�g���N�^
	~CBoost();		// �f�X�g���N�^

	static CBoost *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,			// �C���X�^���X����
		D3DXVECTOR3 size, int nNumber);
	static HRESULT Load(void);										// �e�N�X�`�����[�h
	static void UnLoad(void);										// �e�N�X�`���A�����[�h

	HRESULT Init(const D3DXVECTOR3 pos, 
		const D3DXVECTOR3 size, const int nNum);					// ������
	void Uninit(void);												// �I��
	void Update(void);												// �X�V
	void Draw(void);												// �`��
	void BoostMove(void);											// �u�[�X�g�̍X�V����

private:
	static LPDIRECT3DTEXTURE9 m_apTexture[MAX_LASER_TEXTURE];	// �e�N�X�`�����̃|�C���^
	static LPD3DXMESH m_pMesh;									// ���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER m_pBuffMat;								// �}�e���A�����ւ̃|�C���^
	static DWORD m_nNumMat;										// �}�e���A�����
	D3DXVECTOR3 m_pos;											// ���W
	D3DXVECTOR3 m_rot;											// ��]
	static int m_nBoost;										// boost�i���o�[
	int m_nBoostNum;											// �u�[�X�g�̌ʃi���o�[
	int m_nLife;												// �u�[�X�g�̃��C�t
	int m_nNum;													// �i���o�[
};
#endif