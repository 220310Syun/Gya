#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1), velocity(XMFLOAT3(0, 0, 0))
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Bullet.fbx");
    assert(hModel_ >= 0);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.5f);
    AddCollider(collision);

    velocity = XMFLOAT3(0, -15.0f, 0);
    //this->velocity = XMFLOAT3(direction.x * speed, direction.y * speed, direction.z * speed);
}

//更新
void Bullet::Update()
{
    transform_.position_.x += velocity.x;
    transform_.position_.y += velocity.y;
    transform_.position_.z += velocity.z;

    Debug::Log("Bullet position: X=" + std::to_string(transform_.position_.x) + ", Y=" + std::to_string(transform_.position_.y) + ", Z=" + std::to_string(transform_.position_.z));

    if (transform_.position_.z > 50.0f || transform_.position_.z < -50.0f ||
        transform_.position_.x > 50.0f || transform_.position_.x < -50.0f ||
        transform_.position_.y > 50.0f || transform_.position_.y < -50.0f)
    {
        KillMe();
    }
}

//描画
void Bullet::Draw()
{
    
        Model::SetTransform(hModel_, transform_);
        Model::Draw(hModel_);
    
}



//開放
void Bullet::Release()
{
}

void Bullet::SetDirection(const DirectX::XMFLOAT3& direction) {
    velocity = direction; // 速度ベクトルを設定
}

void Bullet::SetSpeed(float speed) {
    // 速度を方向ベクトルに適用（方向は変えずに速さだけを調整）
    DirectX::XMVECTOR dir = DirectX::XMLoadFloat3(&velocity);
    dir = DirectX::XMVector3Normalize(dir); // 方向ベクトルを正規化
    dir = DirectX::XMVectorScale(dir, speed); // 正規化された方向ベクトルに速度を掛ける
    DirectX::XMStoreFloat3(&velocity, dir); // 結果を velocity に戻す
}

void Bullet::SetPosition(const DirectX::XMFLOAT3& position) {
    this->transform_.position_ = position; // 弾の初期位置を設定
}