//=============================================================================
//
// �e�̏���(���f��) [bullet2.cpp]
// Author : Konishi Yuuto
//
//=============================================================================

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "bullet2.h"
#include "player.h"
#include "game.h"
#include "life.h"
#include "2d_explosion.h"
#include "shock.h"
#include "explosion.h"
#include "bill.h"
#include "splash.h"
#include "camera.h"

//=============================================================================
//�}�N����`
//=============================================================================
#define BULLET2_ATK					(20)		// �U����
#define FOLLOW_TIME_NONE			(23)		// �ʏ�e�̒Ǐ]�^�C��
#define FOLLOW_TIME_BOMB			(125)		// �{���̒Ǐ]�^�C��
#define BEAM_FOLLOW_DISTANCE		(920.0f)	// �Ǐ]���鋗��
#define BOMB_FOLLOW_DISTANCE		(500.0f)	// �Ǐ]���鋗��
#define LASER_FOLLOW_DISTANCE		(500.0f)	// �Ǐ]���鋗��
#define MISSILE_FOLLOW_DISTANCE		(900.0f)	// �Ǐ]���鋗��

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CBullet2::CBullet2()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// �ʒu
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// �ړ���
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// �T�C�Y
	m_user = BULLET2_USER_NONE;					// �g�p��
	m_type = BULLET2_TYPE_NONE;					// �^�C�v
	m_nAtk = 0;									// �U����
	m_nLife = 0;								// ���C�t
	m_nCounter = 0;
	m_pTargetPL = NULL;							//�G�v���C���[�̃|�C���^
	m_fSpeed = 0.0f;
	m_fHeight = 0.0f;
	m_nDamage = 20;
	m_bFollow = false;
}

//=============================================================================
//�o���b�g�N���X�̃f�X�g���N�^
//=============================================================================
CBullet2::~CBullet2()
{

}

//=============================================================================
//�o���b�g�N���X�̃N���G�C�g����
//=============================================================================
CBullet2 * CBullet2::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, 
	const BULLET2_USER user, float fSpeed)
{
	// �������m��
	CBullet2 *pBullet2 = new CBullet2;

	//���������m�ۂł��Ă�����
	if (pBullet2)
	{
		//�����������Ăяo��
		pBullet2->Init(pos, size, user, fSpeed);		// ���������
	}
	else
	{
		return NULL;
	}

	return pBullet2;
}

//=============================================================================
//�o���b�g�N���X�̏���������
//=============================================================================
HRESULT CBullet2::Init(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, 
	const BULLET2_USER user, float fSpeed)
{
	//�ʒu�̐ݒ�
	m_pos = pos;

	//�T�C�Y�̐ݒ�
	m_size = size;

	// �X�s�[�h
	m_fSpeed = fSpeed;

	// �T�C�Y�̐ݒ�
	SetSize(size);

	//�g�p�҂̐ݒ�
	m_user = user;

	//�U���͂̐ݒ�
	m_nAtk = BULLET2_ATK;

	//����������������
	CModel::Init(pos, m_size);

	switch (m_user)
	{
	case BULLET2_USER_PL1:
		//2P�̏��擾
		m_pTargetPL = CGame::GetPlayer(1);

		break;
	case BULLET2_USER_PL2:
		//1P�̏��擾
		m_pTargetPL = CGame::GetPlayer(0);

		break;
	}

	return S_OK;
}

//=============================================================================
//�o���b�g�N���X�̏I������
//=============================================================================
void CBullet2::Uninit(void)
{
	//�I������
	CModel::Uninit();
}

//=============================================================================
//�o���b�g�N���X�̍X�V����
//=============================================================================
void CBullet2::Update(void)
{
	//�ʒu�̎擾
	m_pos = GetPos();
	m_nCounter++;

	bool bTarget = false;

	// �^�[�Q�b�g���擾
	switch (m_user)
	{
	case BULLET2_USER_PL1:
		bTarget = CGame::GetCamera(0)->GetTargetBool();
		break;

	case BULLET2_USER_PL2:
		bTarget = CGame::GetCamera(1)->GetTargetBool();
		break;
	}

	// �Ǐ]�t���O
	if (m_bFollow == false && bTarget == true || m_bFollow == false && m_type == BULLET2_TYPE_BOMB)
	{
		// �����̔���
		if (Follow() == true)
		{
			switch (m_type)
			{
			case BULLET2_TYPE_NONE:

				//�ړ��ʂ̌v�Z
				m_move = VectorMath(D3DXVECTOR3(
					m_pTargetPL->GetPos().x, m_pTargetPL->GetPos().y + 200.0f, m_pTargetPL->GetPos().z), m_fSpeed);
				break;

			case BULLET2_TYPE_BOMB:

				//�ړ��ʂ̌v�Z
				m_move = VectorMath(D3DXVECTOR3(
					m_pTargetPL->GetPos().x, m_pTargetPL->GetPos().y + 200.0f, m_pTargetPL->GetPos().z),
					m_fSpeed);

				// �����̒���
				m_move.y = m_fHeight;
				break;

			case BULLET2_TYPE_LASER:
				m_nCounter++;

				if (m_nCounter >= 2)
				{
					//�ړ��ʂ̌v�Z
					m_move = VectorMath(m_pTargetPL->GetPos(), m_fSpeed);

					m_nCounter = 0;

					m_bFollow = true;
					break;
				}
			}
		}
	}

	//�ړ��ʂ��ʒu�ɗ^����
	m_pos += m_move;

	//���C�t�̐ݒ�
	m_nLife--;

	//�ʒu�̐ݒ�
	SetPos(m_pos);

	if (Collision() == true)
	{
		// �̗͂�0
		m_nLife = 0;
	}

	//���C�t��0�ȉ��̎�
	if (m_nLife <= 0)
	{
		switch (m_type)
		{
		case BULLET2_TYPE_NONE:
			break;

		case BULLET2_TYPE_BOMB:
			// �{���̎�
			CExplosion::Create(D3DXVECTOR3(m_pos.x, 0.0f, m_pos.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f),
				D3DXVECTOR3(EXPLOSION_SIZE_X, EXPLOSION_SIZE_Y, EXPLOSION_SIZE_Z));
			break;

		default:
			break;
		}

		//�I�������Ăяo��
		Uninit();
		return;
	}
}

//=============================================================================
//�o���b�g�N���X�̕`�揈��
//=============================================================================
void CBullet2::Draw(void)
{
	// �`�揈��
	CModel::Draw();
}

//=============================================================================
// �Ǐ]�̃t���O�֐�
//=============================================================================
bool CBullet2::Follow(void)
{
	// �ϐ��錾
	CPlayer *pPlayer = NULL;

	//���@���擾����
	switch (m_user)
	{
	case BULLET2_USER_PL1:
		// 1P�̎�
		pPlayer = CGame::GetPlayer(1);
		break;

	case BULLET2_USER_PL2:
		// 2P�̎�
		pPlayer = CGame::GetPlayer(0);
		break;
	}

	float fPposx = pPlayer->GetPos().x, fPposz = pPlayer->GetPos().z;	// ����̍��W
	float fBposx = m_pos.x, fBposz = m_pos.z;							// �e�̍��W
	float fAngle;														// �p�x

	fAngle = atan2f((fBposx - fPposx), (fBposz - fPposz));				// �p�x�����߂�

	// ����ƒe�̋���
	float fDistance = sqrtf(
		powf((pPlayer->GetPos().x - m_pos.x), 2) +
		powf((pPlayer->GetPos().z - m_pos.z), 2));

	switch (m_type)
	{
	case BULLET2_TYPE_NONE:
	{
		int nFollowDis = BEAM_FOLLOW_DISTANCE + rand() % 20 - rand() % 70;
		// ���̋����ɍs���܂ł͒Ǐ]
		if (fDistance > BEAM_FOLLOW_DISTANCE)
		{
			return true;
		}
		else
		{
			// �t���O��ݒ�
			m_bFollow = true;
		}


	}
		break;

	case BULLET2_TYPE_BOMB:

		// ���̋����ɍs���܂ł͒Ǐ]
		if (fDistance > BOMB_FOLLOW_DISTANCE)
		{
			return true;
		}
		else
		{
			// �t���O��ݒ�
			m_bFollow = true;
		}
		break;

	case BULLET2_TYPE_LASER:

		// ���̋����ɍs���܂ł͒Ǐ]
		if (fDistance > BOMB_FOLLOW_DISTANCE)
		{
			return true;
		}
		else
		{
			// �t���O��ݒ�
			m_bFollow = true;
		}
		break;

		break;
	}

	return false;
}

//=============================================================================
//�o���b�g�N���X�̓����蔻��
//=============================================================================
bool CBullet2::Collision(void)
{
	CPlayer * pPlayer = NULL;

	switch (m_user)
	{
	case BULLET2_USER_PL1:
		//�v���C���[�N���X�փL���X�g
		pPlayer = CGame::GetPlayer(1);
		break;

	case BULLET2_USER_PL2:
		//�v���C���[�N���X�փL���X�g
		pPlayer = CGame::GetPlayer(0);
		break;
	}

	//�ʒu�̎擾
	D3DXVECTOR3 targetPos = pPlayer->GetPos();
	bool bLife = pPlayer->GetLife(0)->GetbLife();

	// �����蔻��
	if (targetPos.x + PLAYER_COLLISION_X / 2 >= m_pos.x - 50.0f &&
		targetPos.x - PLAYER_COLLISION_X / 2 <= m_pos.x + 50.0f &&
		targetPos.y + PLAYER_COLLISION_Y >= m_pos.y - 50.0f &&
		targetPos.y - 0.0f <= m_pos.y + 50.0f &&
		targetPos.z + PLAYER_COLLISION_Z / 2 >= m_pos.z - 50.0f &&
		targetPos.z - PLAYER_COLLISION_Z / 2 <= m_pos.z + 50.0f)
	{
		for (int nCount = 0; nCount < LIFE_NUM; nCount++)
		{
			//�@�v���C���[�̃��C�t�����炷
			if (m_pTargetPL != NULL)
			{
				switch (m_type)
				{
				case BULLET2_TYPE_NONE:
					// �ʏ�̏ꍇ
					m_nDamage = 20;
					break;
				case BULLET2_TYPE_BOMB:
					// �{���̎�
					m_nDamage = 100;
					break;
				case BULLET2_TYPE_LASER:
					// �{���̎�
					m_nDamage = 160;
					break;
				}

				// ���G���Ԃ���Ȃ�������
				if (pPlayer->GetArmor() == false)
				{
					if (bLife == false)
					{
						// ���C�t�����炷����
						m_pTargetPL->GetLife(nCount)->Decrease(m_nDamage, m_user, true);
						m_pTargetPL->GetLife(1)->Decrease(m_nDamage, m_user, true);

						if (m_type != BULLET2_TYPE_NONE)
						{
							// ���ꃂ�[�V�����Ɉڍs
							m_pTargetPL->SetMotion(MOTION_DAMAGE);
						}
					}

					// �v���C���[���̎擾
					switch (m_user)
					{
					case BULLET2_USER_PL1:
						CGame::GetCamera(1)->SetTarget(false);
						break;
					case BULLET2_USER_PL2:
						CGame::GetCamera(0)->SetTarget(false);
						break;
					}
				}

				// ��������
				C2dExplosion::Create(D3DXVECTOR3(m_pTargetPL->GetPos().x, m_pos.y, m_pTargetPL->GetPos().z),
					D3DXVECTOR3(EXPLOSION_SIZE_X_2D, EXPLOSION_SIZE_Y_2D, EXPLOSION_SIZE_Z_2D));
			}

			m_nLife = 0;
			return true;
		}
	}

	for (int nCount = 0; nCount < PRIORITY_MAX; nCount++)
	{
		// �擪�����擾
		CScene *pScene = CScene::GetTop(nCount);

		// NULL�ɂȂ�܂ŌJ��Ԃ�
		while (pScene)
		{
			// �I�u�W�F�N�g�^�C�v���擾
			OBJTYPE type = pScene->GetObjType();

			// ���f���Ȃ�
			if (type == OBJTYPE_MODEL)
			{
				// �L���X�g
				CModel *pModel = (CModel*)pScene;
				CModel::MODEL_TYPE type = pModel->GetType();

				// �����Ȃ�
				if (type == MODEL_TYPE_OBJECT)
				{
					//�ʒu�̎擾
					D3DXVECTOR3 targetPos = pModel->GetPos();

					// �����蔻��
					if (targetPos.x >= m_pos.x - BILL_COLLISION_SIZE_X / 2 &&
						targetPos.x <= m_pos.x + BILL_COLLISION_SIZE_X / 2 &&
						targetPos.y >= m_pos.y - BILL_COLLISION_SIZE_Y / 2 &&
						targetPos.y <= m_pos.y + BILL_COLLISION_SIZE_Y / 2 &&
						targetPos.z >= m_pos.z - BILL_COLLISION_SIZE_Z / 2 &&
						targetPos.z <= m_pos.z + BILL_COLLISION_SIZE_Z / 2)
					{
						for (int nCount = 0; nCount < LIFE_NUM; nCount++)
						{
							// ��������
							CSplash::Create(m_pos,
								D3DXVECTOR3(EXPLOSION_SIZE_X_2D, EXPLOSION_SIZE_Y_2D, EXPLOSION_SIZE_Z_2D));
						}

						m_nLife = 0;
						return true;
					}
				}
			}

			//���̏����擾
			pScene = pScene->GetNext();
		}
	}
	
	return false;
}

//=============================================================================
// �o���b�g�N���X�̂̃x�N�g���v�Z����
//=============================================================================
D3DXVECTOR3 CBullet2::VectorMath(D3DXVECTOR3 TargetPos, float fSpeed)
{

	//2�_�Ԃ̃x�N�g�������߂�i�I�_[�ڕW�n�_] - �n�_[���g�̈ʒu]�j
	D3DXVECTOR3 Vector = TargetPos - m_pos;

	//�x�N�g���̑傫�������߂�(��c^2 = a^2 * b^2)
	float fVectorSize = D3DXVec3Length(&Vector);

	//�P�ʃx�N�g���p�ϐ�
	D3DXVECTOR3 UnitVector;

	//�P�ʃx�N�g�������߂�(���̃x�N�g�� / �x�N�g���̑傫��)
	D3DXVec3Normalize(&UnitVector, &Vector);

	//�P�ʃx�N�g���𑬓x�{�ɂ��ĕԂ�(UnitVector * fSpeed)
	return	UnitVector * fSpeed;
}


//=============================================================================
// �̗͂̐ݒ�
//=============================================================================
void CBullet2::SetLife(int nLife)
{
	m_nLife = nLife;
}

//=============================================================================
// �ړ��ʂ̐ݒ�
//=============================================================================
void CBullet2::SetMove(D3DXVECTOR3 move)
{
	bool bTarget = false;

	// �^�[�Q�b�g���擾
	switch (m_user)
	{
	case BULLET2_USER_PL1:
		bTarget = CGame::GetCamera(0)->GetTargetBool();
		break;

	case BULLET2_USER_PL2:
		bTarget = CGame::GetCamera(1)->GetTargetBool();
		break;
	}

	// �^�[�Q�b�g��ԂȂ�
	if (bTarget == true)
	{
		m_move = VectorMath(D3DXVECTOR3(
			m_pTargetPL->GetPos().x, m_pTargetPL->GetPos().y + 200.0f, m_pTargetPL->GetPos().z), m_fSpeed);
	}
	else
	{
		float fAngle = 0.0f;

		// �^�[�Q�b�g���擾
		switch (m_user)
		{
		case BULLET2_USER_PL1:
			//�J�����p�x�擾
			fAngle = CGame::GetCamera(0)->Get��();
			break;

		case BULLET2_USER_PL2:
			//�J�����p�x�擾
			fAngle = CGame::GetCamera(1)->Get��();
			break;
		}

		m_move = D3DXVECTOR3(cosf(fAngle +D3DXToRadian(270.0f))* m_fSpeed,
		0.0f, sinf(fAngle + D3DXToRadian(270.0f))* m_fSpeed);
	}
}

//=============================================================================
// �^�C�v�̐ݒ�
//=============================================================================
void CBullet2::SetType(BULLET2_TYPE type)
{
	m_type = type;
}

//=============================================================================
// �����̐ݒ�
//=============================================================================
void CBullet2::SetHeight(float fHeight)
{
	m_fHeight = fHeight;
}

//=============================================================================
// �ړ��ʏ��
//=============================================================================
D3DXVECTOR3 CBullet2::GetMove(void)
{
	return m_move;
}

//=============================================================================
// �����̏��
//=============================================================================
float CBullet2::GetHeight(void)
{
	return m_fHeight;
}