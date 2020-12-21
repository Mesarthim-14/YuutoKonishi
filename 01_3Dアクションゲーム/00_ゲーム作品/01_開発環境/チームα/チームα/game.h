#ifndef _GAME_H_
#define _GAME_H_
//=============================================================================
//
// �Q�[���̏��� [game.h]
// Author : Konishi Yuuto
//
//=============================================================================

//***************************************************************************************
// �C���N���[�h�t�@�C��
//***************************************************************************************
#include "scene.h"

//***************************************************************************************
// �}�N����`
//***************************************************************************************
#ifdef VIIEW_PORT_TEST
#endif // VIIEW_PORT_TEST
#define MAX_PLAYER (2)			// �v���C���[�̐�

//***************************************************************************************
// �O���錾
//***************************************************************************************
class CCamera;
class CLight;
class CMeshField;
class CMeshShape;
class CBg;
class CPlayer;
class CTime;
class CUi;
class CUiStart;
class CLockon;
class CBill;
class CContinue;
class CUiEnd;
class CPause;
class CSea;

//***************************************************************************************
// �C���N���[�h�t�@�C��
//***************************************************************************************
class CGame : public CScene
{
public:
	CGame(int nPriority = PRIORITY_0);	// �R���X�g���N�^
	~CGame();							// �f�X�g���N�^

	HRESULT Init(const D3DXVECTOR3 pos, const D3DXVECTOR3 size);	// ����������
	void Uninit(void);												// �I������
	void Update(void);												// �X�V����
	void Draw(void);												// �`�揈��
	void SetGame(void);												// �Q�[���̐ݒ�
	void ResetGame(void);											// ���Z�b�g����

	static CGame* Create();											// �Q�[���������
	static CCamera *GetCamera(int nCount);							// �J�����̃|�C���^���
	static CLight *GetLight(void);									// ���C�g�̃|�C���^���
	static CPlayer *GetPlayer(int nCount);							// �v���C���[�̃|�C���^���
	static CTime *GetTime(void);									// �^�C���̃|�C���^���
	static CMeshShape*GetSphere();									// �X�t�B�A�̃|�C���^���
	static CUi *GetUi(void);										// UI�̃|�C���^���
	static CUiStart *GetUiStart(void);								// �X�^�[�g��UI�̃|�C���^���
	static CUiEnd *GetUiEnd(void);									// �I�����̃|�C���^���
	static CLockon *GetLockon(void);								// ���b�N�I���̃|�C���^���
	static CBill *GetBill(void);									// �r���̃|�C���^���
	static CContinue *GetContinue(void);							// �R���e�B�j���[�̃|�C���^���
	static CPause *GetPause(void);									// �|�[�Y��ʂ̃|�C���^���

private:	
	static CCamera *m_apCamera[MAX_PLAYER];		// �J�����̃|�C���^	
	static CLight *m_pLight;					// ���C�g�̃|�C���^
	static CMeshField *m_pMeshField;			// ���b�V���t�B�[���h�̃|�C���^
	static CMeshShape * m_pSphere;				// ���b�V���X�t�B�A�̃|�C���^
	static CBg *m_pBg;							// �w�i�̃|�C���^
	static CPlayer *m_apPlayer[MAX_PLAYER];		// �v���C���[�̃|�C���^
	static CTime *m_pTime;						// �^�C���̃|�C���^
	static CUi *m_pUi;							// ui�̃|�C���^
	static CUiStart *m_pUiStart;				// uistart�̃|�C���^
	static CUiEnd *m_pUiEnd;					// uiend�̃|�C���^
	static CLockon *m_pLockon;					// ���b�N�I���̃|�C���^
	static CBill *m_pBill;						// �r���̃|�C���^
	static CSea *m_pSea;						// �C�̃|�C���^
	static CContinue *m_pContinue;				// �R���e�j���[�̃|�C���^
	static CPause *m_pPause;					// �|�[�Y�̃|�C���^
	static int m_nRoundNum;						// ���݂̃��E���h��
	static int m_aWinNum[MAX_PLAYER];			// ����������
	LPD3DXFONT m_pFont;							// �f�o�b�N�p�t�H���g
	bool m_bGameEnd;							// �Q�[���̃G���h�t���O
};
#endif