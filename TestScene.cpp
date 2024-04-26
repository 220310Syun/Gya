#include "TestScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"
//#include "EnemyGroup.h"

//コンストラクタ
TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene"){
	//enemyGroup = new EnemyGroup(this);
}


//初期化
void TestScene::Initialize()
{
	Instantiate<Player>(this);

	

	int screenWidth = GetPrivateProfileInt("SCREEN", "Width", 800, ".\\setup.ini");      // スクリーンの幅
	int screenHeight = GetPrivateProfileInt("SCREEN", "Height", 600, ".\\setup.ini");    // スクリーンの高さ

	const int numEnemiesPerRow = 10;  // 一行あたりの敵の数
	const float spacingX = 3.5f;  // X軸方向の間隔
	const float spacingY = 3.5f;  // Y軸方向の間隔（行間の間隔）
	float startX = -spacingX * (numEnemiesPerRow - 1) / 2.0f;  // 中心を基準に配置
	//const float delayIncrement = 1.0f;

	// Y軸の初期位置
	float startY = 15.0f;

	for (int row = 0; row < 3; row++) {  // 3列
		//float delay = row * delayIncrement;
		for (int col = 0; col < numEnemiesPerRow; col++) {// 各列に10体
			//Enemy* enemy = new Enemy(this, col);
			Enemy* enemy = Instantiate<Enemy>(this);
			float posX = startX + col * spacingX;  // X座標
			float posY = startY - row * spacingY;  // Y座標を行ごとにずらす
			float posZ = 0.0f;  // Z座標は0で固定

			//Enemy* enemy = Instantiate<Enemy>(this);

			enemy->SetPosition(XMFLOAT3(posX, posY, posZ));
		}
	}




	Camera::SetPosition(XMFLOAT3(0, 0, -45));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));
}

//更新
void TestScene::Update()
{

	GameObject* pGameObject = FindObject("Enemy");
	if (pGameObject == nullptr)
	
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}

	//GameObject* player = FindObject("Player");
	//if (player == nullptr)  // プレイヤーが削除されたかどうかをチェック
	//{
	//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	//if (pSceneManager != nullptr) {
	//	pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);  // ゲームオーバーシーンへ切り替え
	//    }
	//}
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}