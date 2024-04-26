#include "EnemyBullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Bullet.h"
#include "Engine/SceneManager.h"
#include "Player.h"

// コンストラクタ
EnemyBullet::EnemyBullet(GameObject* parent)
    : GameObject(parent, "EnemyBullet"), hModel_(-1), velocity(XMFLOAT3(0, 0, 0))
{
}

EnemyBullet::~EnemyBullet()
{
}

// 初期化
void EnemyBullet::Initialize()
{
    hModel_ = Model::Load("EnemyBullet.fbx");
    assert(hModel_ >= 0);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
    AddCollider(collision);

    velocity = XMFLOAT3(0, -15.0f, 0);
}

// 更新
void EnemyBullet::Update()
{
    transform_.position_.x += velocity.x;
    transform_.position_.y += velocity.y;
    transform_.position_.z += velocity.z;

    // 画面外に出たら削除
    if (transform_.position_.z > 50.0f || transform_.position_.z < -50.0f ||
        transform_.position_.x > 50.0f || transform_.position_.x < -50.0f ||
        transform_.position_.y > 50.0f || transform_.position_.y < -50.0f)
    {
        KillMe();
    }
}

// 描画
void EnemyBullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

// 開放
void EnemyBullet::Release()
{
}

// 弾の方向を設定
void EnemyBullet::SetDirection(const XMFLOAT3& direction) {
    velocity = direction;
}

// 弾の速度を設定
void EnemyBullet::SetSpeed(float speed) {
    DirectX::XMVECTOR dir = DirectX::XMLoadFloat3(&velocity);
    dir = DirectX::XMVector3Normalize(dir); // 方向ベクトルを正規化
    dir = DirectX::XMVectorScale(dir, speed); // 正規化された方向ベクトルに速度を掛ける
    DirectX::XMStoreFloat3(&velocity, dir); // 結果を velocity に戻す
}

// 弾の位置を設定
void EnemyBullet::SetPosition(const XMFLOAT3& position) {
    this->transform_.position_ = position;
}

void EnemyBullet::OnCollision(GameObject* pTarget) {
    if (pTarget->GetObjectName() == "Player") {
        // 衝突したオブジェクトがプレイヤーの場合の処理
        SceneManager* sceneManager = (SceneManager*)FindObject("SceneManager");
        if (sceneManager) {
            sceneManager->ChangeScene(SCENE_ID_GAMEOVER);
            
    }
        KillMe();  // 弾の削除
        pTarget->KillMe();  // プレイヤーの削除
    }
}