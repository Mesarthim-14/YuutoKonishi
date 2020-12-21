#ifndef _RENDERER_H_
#define _RENDERER_H_
//=============================================================================
//
// �����_���[���� [renderer.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"

//=============================================================================
// �O���錾
//=============================================================================
class CShader;

//=============================================================================
//�����_�����O�N���X
//=============================================================================
class CRenderer
{
public:
	CRenderer();	// �R���X�g���N�^
	~CRenderer();	// �f�X�g���N�^

	HRESULT Init(HWND hWnd, bool bWindow);	// ����������
	void Uninit(void);						// �I������
	void Update(void);						// �X�V����
	void Draw(void);						// �`�揈��

	bool SetUpViewport(int nNumber);		// �r���[�|�[�g�ݒ�
	LPDIRECT3DDEVICE9 GetDevice(void);		// �f�o�C�X���
	D3DVIEWPORT9 GetViewPort(int nCount);	// �r���[�|�[�g���
private:
	LPDIRECT3DDEVICE9 m_pD3DDevice;				// Device�I�u�W�F�N�g(�`��ɕK�v)
	LPDIRECT3D9	m_pD3D;							// Direct3D�I�u�W�F�N�g
	LPDIRECT3D9 m_pD3DInterface;				// DirectX�C���^�[�t�F�[�X
	D3DPRESENT_PARAMETERS *m_pD3DPresentParam;	// �v���[���e�[�V�����p�����[�^
	CShader *m_pShader;							// �V�F�[�_�̃|�C���^
	D3DVIEWPORT9 m_view_port[2];				// �r���[�|�[�g�̐ݒ�
};

#endif