#include "GameOverScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//コンストラクタ
GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1)
{
}

//初期化
void GameOverScene::Initialize()
{
	pText = new Text;
	//pText = std::make_unique<Text>();
	pText->Initialize();
	//画像データのロード
	hPict_ = Image::Load("GAMEOVER4.png");
	assert(hPict_ >= 0);
}

//更新
void GameOverScene::Update()
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
void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	pText->Draw(500, 550, "PUSH 'SPACE' TITLE");
}

//開放
void GameOverScene::Release()
{
}
