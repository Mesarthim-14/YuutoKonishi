#ifndef _MISSILE_H_
#define _MISSILE_H_
//=============================================================================
//
// �~�T�C������ [missile.h]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "scene.h"

//=============================================================================
//�}�N����`
//=============================================================================
#define MAX_MODEL_MISSILE_PARTS (2)			// �p�[�c��
#define MISSILE_SPPED			(45)		// �~�T�C���̑��x
#define MISSILE_SIZE_X			(3.0f)		// �T�C�Y
#define MISSILE_SIZE_Y			(3.0f)		// �T�C�Y
#define MISSILE_SIZE_Z			(3.0f)		// �T�C�Y

//=============================================================================
//�O���錾
//=============================================================================
class CModelAnime;
class CPlayer;

//=============================================================================
//�~�T�C���N���X
//=============================================================================
class CMissile : public CScene
{
public:

	// ���f���t�@�C�����̍\����
	typedef struct
	{
		char xFileName[1024];	// �t�@�C���l�[��
		D3DXVECTOR3 offsetPos;	// �ʒu�̃I�t�Z�b�g���
		D3DXVECTOR3 offsetRot;	// �����̃I�t�Z�b�g���
		int nParent;			// �e���
	}MODELFILLEs;

	// �e�̎g�p�Ҕ��ʗp�̗񋓌^
	typedef enum
	{
		MISSILE_USER_NONE = -1,	// �����l
		MISSILE_USER_PL1,		// PL1
		MISSILE_USER_PL2,		// PL2
		MISSILE_USER_MAX		// �ő吔
	}MISSILE_USER;

	CMissile(int nPriority = PRIORITY_0);	// �R���X�g���N�^
	~CMissile();							// �f�X�g���N�^

	static CMissile *Create(const D3DXVECTOR3 pos, 
		const D3DXVECTOR3 size,const MISSILE_USER user, float fSpeed);	// �C���X�^���X����

	HRESULT Init(const D3DXVECTOR3 pos, const D3DXVECTOR3 size);		// ����������
	void Uninit(void);													// �I������
	void Update(void);													// �X�V����
	void Draw(void);													// �`�揈��
	void SetRot(D3DXVECTOR3 rot);										// �p�x�̐ݒ�
	void SetMove(D3DXVECTOR3 move);										// �ړ��̏���
	HRESULT ReadFile(void);												// �t�@�C���ǂݍ���
	bool Collision(void);												// �����蔻��
	D3DXVECTOR3 VectorMath(D3DXVECTOR3 TargetPos,						// �Ǐ]����
		float fSpeed);
	bool Follow(void);													// �Ǐ]
private:
	D3DXVECTOR3 m_pos;										// �ʒu
	D3DXVECTOR3 m_rot;										// ����
	D3DXVECTOR3 m_move;										// �ړ���
	D3DXVECTOR3 m_size;										// �T�C�Y
	int m_nLife;											// ���C�t
	CModelAnime *m_apModelAnime[MAX_MODEL_MISSILE_PARTS];	// �K�w���f���N���X�̃|�C���^�ϐ�
	int m_nCounter;											// �Ǐ]�J�E���^�[
	D3DXMATRIX m_mtxWorld;									// ���[���h�}�g���b�N�X
	MISSILE_USER m_user;									// �g�p��
	CPlayer *m_pTargetPL;									//�G�v���C���[�̃|�C���^
	int m_nDamage;											//�_���[�W��
	float m_fSpeed;											// ����
	float m_fHeight;										// ����
	bool m_bFollow;											// �Ǐ]�p�̃t���O
};

#endif 