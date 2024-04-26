#include "TestScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"
//#include "EnemyGroup.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene"){
	//enemyGroup = new EnemyGroup(this);
}


//������
void TestScene::Initialize()
{
	Instantiate<Player>(this);

	

	int screenWidth = GetPrivateProfileInt("SCREEN", "Width", 800, ".\\setup.ini");      // �X�N���[���̕�
	int screenHeight = GetPrivateProfileInt("SCREEN", "Height", 600, ".\\setup.ini");    // �X�N���[���̍���

	const int numEnemiesPerRow = 10;  // ��s������̓G�̐�
	const float spacingX = 3.5f;  // X�������̊Ԋu
	const float spacingY = 3.5f;  // Y�������̊Ԋu�i�s�Ԃ̊Ԋu�j
	float startX = -spacingX * (numEnemiesPerRow - 1) / 2.0f;  // ���S����ɔz�u
	//const float delayIncrement = 1.0f;

	// Y���̏����ʒu
	float startY = 15.0f;

	for (int row = 0; row < 3; row++) {  // 3��
		//float delay = row * delayIncrement;
		for (int col = 0; col < numEnemiesPerRow; col++) {// �e���10��
			//Enemy* enemy = new Enemy(this, col);
			Enemy* enemy = Instantiate<Enemy>(this);
			float posX = startX + col * spacingX;  // X���W
			float posY = startY - row * spacingY;  // Y���W���s���Ƃɂ��炷
			float posZ = 0.0f;  // Z���W��0�ŌŒ�

			//Enemy* enemy = Instantiate<Enemy>(this);

			enemy->SetPosition(XMFLOAT3(posX, posY, posZ));
		}
	}




	Camera::SetPosition(XMFLOAT3(0, 0, -45));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));
}

//�X�V
void TestScene::Update()
{

	GameObject* pGameObject = FindObject("Enemy");
	if (pGameObject == nullptr)
	
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}

	//GameObject* player = FindObject("Player");
	//if (player == nullptr)  // �v���C���[���폜���ꂽ���ǂ������`�F�b�N
	//{
	//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	//if (pSceneManager != nullptr) {
	//	pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);  // �Q�[���I�[�o�[�V�[���֐؂�ւ�
	//    }
	//}
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}