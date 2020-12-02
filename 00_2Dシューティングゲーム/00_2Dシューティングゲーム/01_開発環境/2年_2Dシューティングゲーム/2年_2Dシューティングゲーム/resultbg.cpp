//=============================================================================
//
// リザルト背景の処理 [resultbg.cpp]
// Author : Konishi Yuuto
//
//=============================================================================

//====================================================================
// インクルード
//====================================================================
#include "resultbg.h"
#include "renderer.h"
#include "manager.h"

//=============================================================================
// static初期化
//=============================================================================
LPDIRECT3DTEXTURE9 CResultBg::m_apTexture[MAX_RESULTBG_TEXTURE] = {};

//====================================================================
// ポリゴン生成
//====================================================================
CResultBg * CResultBg::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, TYPE type)
{
	// インスタンス生成
	CResultBg *pResultBg = new CResultBg;

	if (pResultBg != NULL)
	{
		// 初期化処理
		pResultBg->Init(pos, size, type);

		// テクスチャの設定
		pResultBg->BindTexture(m_apTexture[0]);
	}
	return pResultBg;
}

//====================================================================
// コンストラクタ
//====================================================================
CResultBg::CResultBg()
{
}

//====================================================================
// デストラクタ
//====================================================================
CResultBg::~CResultBg()
{
}

//====================================================================
// 初期化処理
//====================================================================
HRESULT CResultBg::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, TYPE type)
{
	// 初期化処理
	CScene2D::Init(pos, size, type);

	return S_OK;
}

//====================================================================
// 終了処理
//====================================================================
void CResultBg::Uninit(void)
{
	// 終了処理
	CScene2D::Uninit();
}

//====================================================================
// 更新処理
//====================================================================
void CResultBg::Update(void)
{
	// 更新処理
	CScene2D::Update();
}

//====================================================================
// 描画処理
//====================================================================
void CResultBg::Draw(void)
{
	// 描画処理
	CScene2D::Draw();

}

//====================================================================
// テクスチャロード
//====================================================================
HRESULT CResultBg::Load(void)
{
	// レンダラーの情報を受け取る
	CRenderer *pRenderer = NULL;
	pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "date/TEXTURE/result.png",
		&m_apTexture[0]);

	return S_OK;
}

//====================================================================
// テクスチャアンロード
//====================================================================
void CResultBg::UnLoad(void)
{
	for (int nCount = 0; nCount < MAX_RESULTBG_TEXTURE; nCount++)
	{
		// テクスチャの開放
		if (m_apTexture[nCount] != NULL)
		{
			m_apTexture[nCount]->Release();
			m_apTexture[nCount] = NULL;
		}
	}
}