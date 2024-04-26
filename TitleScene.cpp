#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"


TitleScene::TitleScene(GameObject* parent)
    : GameObject(parent, "TitleScene"), pText(nullptr), titleImageId_(-1) {
}

TitleScene::~TitleScene() { // デストラクタを実装

}


void TitleScene::Initialize() {
    pText = new Text;
    //pText = std::make_unique<Text>();
    pText->Initialize();

    titleImageId_ = Image::Load("back.png");
    //if (titleImageId_ < 0) {
        // エラーログを出力するなどのエラーハンドリング
    //}
}

void TitleScene::Update() {
    // タイトル画面での更新処理（ユーザー入力など）
    if (Input::IsKeyDown(DIK_SPACE)) {
        // シーンマネージャーにシーン切り替えを指示
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        if (pSceneManager != nullptr) {
            pSceneManager->ChangeScene(SCENE_ID_TEST); // 次のシーンIDに切り替え
        }
    }
}

void TitleScene::Draw() {
    Image::SetTransform(titleImageId_, transform_); // 必要に応じて位置やサイズを調整
    Image::Draw(titleImageId_);

    //if (pText) {
    pText->Draw(560, 250, "GALAXIAN");
    pText->Draw(500, 450, "PUSH 'SPACE' START");
    //}

}



/*void TitleScene::Draw() {
    if (titleImageId_ >= 0) {
        Image::Draw(titleImageId_);
    }
}*/

void TitleScene::Release() {
    //if (pText) { // pTextがヌルでないことを確認
    //    pText->Release();
    //    delete pText; // 削除を追加
    //    pText = nullptr;
    //}
}
