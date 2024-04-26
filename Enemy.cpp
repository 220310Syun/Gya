#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"
//#include "Bullet.h"
#include <random>
#include <iostream>
#include "Player.h"
#include "EnemyBullet.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"),
    hModel_(-1), fireRate_(2.0f), timeSinceLastShot_(0.0f)
{
    initialDelay_ = static_cast<float>(rand()) / RAND_MAX * 3.0f;
    timeSinceLastShot_ = -initialDelay_;
}

//デストラクタ
Enemy::~Enemy()
{
    for (auto bullet : bullets_) {
        delete bullet;
    }
    bullets_.clear();
}

//初期化
void Enemy::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);

    /*transform_.position_.x = (float)(rand() % 401 - 200) / 10;//rand() %範囲+最小値;
    transform_.position_.y = 15.0f;
    transform_.position_.z = 0.0f;*/

    transform_.scale_ = XMFLOAT3(1.0f, 1.0f, 0.5f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
    AddCollider(collision);

    //timeSinceLastShot_ = -initialDelay_;

}

//更新
void Enemy::Update()
{
    timeSinceLastShot_ += 1.0f / 60.0f; // 仮定: ゲームは60FPSで動作している
    if (timeSinceLastShot_ >= fireRate_) {
        // 弾を発射するロジック
        //auto bullet = new Bullet(this);
        //XMFLOAT3 bulletDirection = XMFLOAT3(0, -1, 0); // 下向きに発射
        //bullet->Initialize(transform_.position_, bulletDirection);
        //bullet->Initialize(/*transform_.position_, XMFLOAT3(0, -1, 0)*/);
        // 弾の位置や方向の設定など、必要に応じてBulletインスタンスの設定を行う
        FireBullet();
        timeSinceLastShot_ = 0.0f;
    }
    
    fireRate_ = static_cast<float>(rand()) / RAND_MAX * 3.0f + 2.0f;

    for (auto& bullet : bullets_) {
        bullet->Update();
    }

    GameObject* Enemy;
    Enemy = FindObject("Enemy");
    float Pposx = Enemy->GetPosition().x;
    if (i == 1)
    {
        transform_.position_.x += 0.1f;
        if (Pposx >= 15.0f)
        {
            i = 0;
        }
    }
    else if (i == 0)
    {
        transform_.position_.x -= 0.1f;
        if (Pposx <= -15.0f)
        {
            i = 1;
        }
    }
}

void Enemy::FireBullet() {
    auto bullet = new EnemyBullet(this); // 弾のインスタンスを生成


    DirectX::XMFLOAT3 direction = { 0.0f, -1.0f, 0.0f }; // 下向き

    // 速度を設定
    float speed = 0.28f;

    bullet->Initialize(); // Bulletの初期化
    
    DirectX::XMFLOAT3 bulletStartPosition = this->transform_.position_;
    bulletStartPosition.y -= 3.0f;
    bulletStartPosition.z = this->transform_.position_.z;

    bullet->SetPosition(bulletStartPosition/*this->transform_.position_*/);
    bullet->SetDirection(direction/*bulletDirection*/); // 方向を設定
    bullet->SetSpeed(speed); // 速度を設定

    bullets_.push_back(bullet); // 管理リストに追加
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    for (auto& bullet : bullets_) {
        bullet->Draw();
    }
}

//開放
void Enemy::Release()
{
}

//何かに当たった
void Enemy::OnCollision(GameObject* pTarget)
{
    //当たったときの処理   
    //弾に当たったとき
    if (pTarget->GetObjectName() == "Bullet")
    {
        KillMe();
        pTarget->KillMe();
    }
}
