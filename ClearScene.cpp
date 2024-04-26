#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

//コンストラクタ
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), hPict_(-1)
{
}

//初期化
void ClearScene::Initialize()
{
	pText = new Text;
	//pText = std::make_unique<Text>();
	pText->Initialize();

	//画像データのロード
	hPict_ = Image::Load("CLEAR.png");
	assert(hPict_ >= 0);
}

//更新
void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		// シーンマネージャーにシーン切り替えを指示
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		if (pSceneManager != nullptr) {
			pSceneManager->ChangeScene(SCENE_ID_TITLE); // 次のシーンIDに切り替え
		}
	}
}

//描画
void ClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	pText->Draw(500, 450, "PUSH 'SPACE' TITLE");
}

//開放
void ClearScene::Release()
{
}
