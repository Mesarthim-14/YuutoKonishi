#ifndef _2D_EXPLOSION_H_
#define _2D_EXPLOSION_H_
//=====================================================
//
// 2D�̔����N���X�w�b�_�[ [2d_explosion.h]
// Author : Konishi Yuuto
//
//=====================================================

//=====================================================
// �C���N���[�h
//=====================================================
#include "billboard.h"

//=====================================================
// �}�N����`
//=====================================================
#define EXPLOSION_SIZE_X_2D		(300)		// �����̃T�C�Y
#define EXPLOSION_SIZE_Y_2D		(300)		// �����̃T�C�Y
#define EXPLOSION_SIZE_Z_2D		(300)		// �����̃T�C�Y

//=====================================================
// �O���錾
//=====================================================
class CBillboard;

//=====================================================
// �r���{�[�h�N���X
//=====================================================
class C2dExplosion : public CBillboard
{
public:
	C2dExplosion();			// �R���X�g���N�^
	~C2dExplosion();		// �f�X�g���N�^

	HRESULT Init(const D3DXVECTOR3 pos, const D3DXVECTOR3 size);		// ����������
	void Uninit(void);													// �I������
	void Update(void);													// �X�V����
	void Draw(void);													// �`�揈��

	static C2dExplosion *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);		// �N���G�C�g����
	static HRESULT Load(void);											// �e�N�X�`�����[�h
	static void UnLoad(void);											// �e�N�X�`���A�����[�h

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;				// �|���S���̃e�N�X�`��
};

#endif