#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"


TitleScene::TitleScene(GameObject* parent)
    : GameObject(parent, "TitleScene"), pText(nullptr), titleImageId_(-1) {
}

TitleScene::~TitleScene() { // �f�X�g���N�^������

}


void TitleScene::Initialize() {
    pText = new Text;
    //pText = std::make_unique<Text>();
    pText->Initialize();

    titleImageId_ = Image::Load("back.png");
    //if (titleImageId_ < 0) {
        // �G���[���O���o�͂���Ȃǂ̃G���[�n���h�����O
    //}
}

void TitleScene::Update() {
    // �^�C�g����ʂł̍X�V�����i���[�U�[���͂Ȃǁj
    if (Input::IsKeyDown(DIK_SPACE)) {
        // �V�[���}�l�[�W���[�ɃV�[���؂�ւ����w��
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        if (pSceneManager != nullptr) {
            pSceneManager->ChangeScene(SCENE_ID_TEST); // ���̃V�[��ID�ɐ؂�ւ�
        }
    }
}

void TitleScene::Draw() {
    Image::SetTransform(titleImageId_, transform_); // �K�v�ɉ����Ĉʒu��T�C�Y�𒲐�
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
    //if (pText) { // pText���k���łȂ����Ƃ��m�F
    //    pText->Release();
    //    delete pText; // �폜��ǉ�
    //    pText = nullptr;
    //}
}
