#ifndef _PARTICLE_H_
#define _PARTICLE_H_
//=============================================================================
//
// �p�[�e�B�N���N���X�w�b�_�[ [particl.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "billboard.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define PARTICLE_SIZE_X			(20)		// ���T�C�Y
#define PARTICLE_SIZE_Y			(5)			// �c�T�C�Y
#define MAX_PARTICLE_TEXTURE	(1)			// �e�N�X�`����
#define PARTICLE_LIFE			(14)		// �p�[�e�B�N���̗̑�
#define PARTICLE_BASE_ANGLE		(90)		// �ΉԂ̌���
#define PARTICLE_NUM			(50)		// �p�[�e�B�N���̐�
#define PARTICLE_SPPED			(1)			// �X�s�[�h
#define PARTICLE_DISTANCE		(20)		// ��������
#define PARTICLE_ANGLE			(30)		// �p�x

//=============================================================================
// �O���錾
//=============================================================================
class CBillboard;

//=============================================================================
// BG�N���X
//=============================================================================
class CParticle : public CBillboard
{
public:
	CParticle();			// �R���X�g���N�^
	~CParticle();			// �f�X�g���N�^

	HRESULT Init(const D3DXVECTOR3 pos, const D3DXVECTOR3 size);	// ����������
	void Uninit(void);												// �I������
	void Update(void);												// �X�V����
	void Draw(void);												// �`�揈��

	static CParticle * Create(
		D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col,
		int nAngle, int nBaseAngle, 
		int nDistance, int nLife, int nSpeed);						// �|���S������

	static HRESULT Load(void);										// �e�N�X�`�����[�h
	static void UnLoad(void);										// �e�N�X�`���A�����[�h

	void SetColor(D3DXCOLOR col);									// �p�[�e�B�N���̃J���[��ݒ�
	void SetLife(int nLife);										// ���C�t�̐ݒ�

private:
	int m_nLife;													// �̗�
	static LPDIRECT3DTEXTURE9 m_apTexture[MAX_PARTICLE_TEXTURE];	// �e�N�X�`�����̃|�C���^
};

#endif