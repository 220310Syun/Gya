#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

//�R���X�g���N�^
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), hPict_(-1)
{
}

//������
void ClearScene::Initialize()
{
	pText = new Text;
	//pText = std::make_unique<Text>();
	pText->Initialize();

	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("CLEAR.png");
	assert(hPict_ >= 0);
}

//�X�V
void ClearScene::Update()
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
void ClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);

	pText->Draw(500, 450, "PUSH 'SPACE' TITLE");
}

//�J��
void ClearScene::Release()
{
}
