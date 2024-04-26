#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "Engine/Debug.h"
#include "Engine/GameObject.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"
#include "Enemy.h"
//#include "EnemyBullet.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Player.fbx");
    assert(hModel_ >= 0);

    transform_.position_.x = 0.0f; // X軸で-1
    transform_.position_.y = -15.0f; // Y軸で-1
    transform_.position_.z = 0.0f;

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
    AddCollider(collision);
}

//更新
void Player::Update()
{ 

    if (Input::IsKey(DIK_RIGHT))
    {
        //何らかの処理
        transform_.position_.x += 0.3f;
    }
    if (Input::IsKey(DIK_LEFT))
    {
        //何らかの処理
        transform_.position_.x -= 0.3f;
    }
    if (Input::IsKeyDown(DIK_SPACE))
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        //pBullet->SetPosition(transform_.position_);

        //DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(0, 1, 0); // 正規化された方向ベクトル（真上）
        //pBullet->SetDirection(direction); // 方向を設定

        //float speed = 0.6f; // 希望する速度
        //pBullet->SetSpeed(speed);

        XMFLOAT3 bulletStartPosition = transform_.position_;
        bulletStartPosition.y += 1.5;  // Y軸方向に適当な距離をオフセット
        pBullet->SetPosition(bulletStartPosition);
        DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(0, 1, 0); // 上向き
        pBullet->SetDirection(direction);
        pBullet->SetSpeed(0.6f);
    }
    
    //Debug::Log("Player position: X=" + std::to_string(transform_.position_.x) + ", Y=" + std::to_string(transform_.position_.y) + ", Z=" + std::to_string(transform_.position_.z));
}

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{

    Debug::Log("Collision with: " + pTarget->GetObjectName());
    //if (pTarget->GetObjectName() == "Bullet" && pTarget->GetParent() != this) {
    if (pTarget->GetObjectName() == "EnemyBullet") {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        if (pSceneManager != nullptr) {
            pSceneManager->ChangeScene(SCENE_ID_GAMEOVER); // ゲームオーバーシーンへ切り替え
        }
        KillMe();  // プレイヤーを削除
        pTarget->KillMe();  // 弾も削除
    }
}

//    if (pTarget->GetObjectName() == "Bullet") {
//        if (pTarget->GetParent() != this) {  // 自身が発射した弾でないことを確認
//            SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
//            if (pSceneManager != nullptr) {
//                pSceneManager->ChangeScene(SCENE_ID_GAMEOVER); // ゲームオーバーシーンへ切り替え
//            }
//            KillMe();  // プレイヤーを削除
//            pTarget->KillMe();  // 弾も削除
//        }
//    }
//}