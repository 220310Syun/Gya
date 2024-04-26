#include "GameOverScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//�R���X�g���N�^
GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1)
{
}

//������
void GameOverScene::Initialize()
{
	pText = new Text;
	//pText = std::make_unique<Text>();
	pText->Initialize();
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("GAMEOVER4.png");
	assert(hPict_ >= 0);
}

//�X�V
void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		// �V�[���}�l�[�W���[�ɃV�[���؂�ւ����w��
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		if (pSceneManager != nullptr) {
			pSceneManager->ChangeScene(SCENE_ID_TITLE); // ���̃V�[��ID�ɐ؂�ւ�
		}
	}
}

//�`��
void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	pText->Draw(500, 550, "PUSH 'SPACE' TITLE");
}

//�J��
void GameOverScene::Release()
{
}
