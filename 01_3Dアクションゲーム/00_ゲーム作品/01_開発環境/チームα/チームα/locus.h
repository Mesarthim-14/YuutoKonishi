#ifndef _LOCUS_H_
#define _LOCUS_H_
//=============================================================================
//
// �O�Ղ̏��� [locus.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=========================================================================
// �C���N���[�h
//=========================================================================
#include "scene3D.h"

//=========================================================================
// �}�N����`
//=========================================================================
#define LOCUS_SIZE_X	(30.0f)		// �T�C�Y
#define LOCUS_SIZE_Y	(100.0f)	// �T�C�Y
#define LOCUS_SIZE_Z	(50.0f)		// �T�C�Y
#define LOCUS_LIFE		(8)			// �O�Ղ̃��C�t

//=========================================================================
// �O�ՃN���X
//=========================================================================
class CLocus :public CScene3D
{
public:
	CLocus();		// �R���X�g���N�^
	~CLocus();		// �f�X�g���N�^

	HRESULT Init(const D3DXVECTOR3 pos, const D3DXVECTOR3 size);		// ������
	HRESULT Init(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2,
		D3DXVECTOR3 posOld1, D3DXVECTOR3 posOld2);						// ����������
	void Uninit(void);													// �I������
	void Update(void);													// �X�V����
	void Draw(void);													// �`�揈��

	static CLocus *Create(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2,
		D3DXVECTOR3 posOld1, D3DXVECTOR3 posOld2,
		D3DXVECTOR3 rot, D3DXVECTOR3 size, int nLife);				// �C���X�^���X����
	static HRESULT Load(void);										// �e�N�X�`�����[�h
	static void UnLoad(void);										// �e�N�X�`���A�����[�h

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;		// �e�N�X�`���|�C���^
	int m_nLife;								// ���C�t
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;			// ���_�o�b�t�@�|�C���^
	D3DXMATRIX	m_mtxWorld;						// ���[���h�}�g���N�X
	D3DXVECTOR3 m_pos;							// �ʒu
	D3DXVECTOR3 m_posOld;						// �Â����W
	D3DXVECTOR3 m_size;							// �T�C�Y
	D3DXVECTOR3 m_rot;							// ����

};
#endif