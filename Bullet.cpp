#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1), velocity(XMFLOAT3(0, 0, 0))
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Bullet.fbx");
    assert(hModel_ >= 0);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.5f);
    AddCollider(collision);

    velocity = XMFLOAT3(0, -15.0f, 0);
    //this->velocity = XMFLOAT3(direction.x * speed, direction.y * speed, direction.z * speed);
}

//�X�V
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

//�`��
void Bullet::Draw()
{
    
        Model::SetTransform(hModel_, transform_);
        Model::Draw(hModel_);
    
}



//�J��
void Bullet::Release()
{
}

void Bullet::SetDirection(const DirectX::XMFLOAT3& direction) {
    velocity = direction; // ���x�x�N�g����ݒ�
}

void Bullet::SetSpeed(float speed) {
    // ���x������x�N�g���ɓK�p�i�����͕ς����ɑ��������𒲐��j
    DirectX::XMVECTOR dir = DirectX::XMLoadFloat3(&velocity);
    dir = DirectX::XMVector3Normalize(dir); // �����x�N�g���𐳋K��
    dir = DirectX::XMVectorScale(dir, speed); // ���K�����ꂽ�����x�N�g���ɑ��x���|����
    DirectX::XMStoreFloat3(&velocity, dir); // ���ʂ� velocity �ɖ߂�
}

void Bullet::SetPosition(const DirectX::XMFLOAT3& position) {
    this->transform_.position_ = position; // �e�̏����ʒu��ݒ�
}