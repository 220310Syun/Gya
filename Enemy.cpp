#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"
//#include "Bullet.h"
#include <random>
#include <iostream>
#include "Player.h"
#include "EnemyBullet.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"),
    hModel_(-1), fireRate_(2.0f), timeSinceLastShot_(0.0f)
{
    initialDelay_ = static_cast<float>(rand()) / RAND_MAX * 3.0f;
    timeSinceLastShot_ = -initialDelay_;
}

//�f�X�g���N�^
Enemy::~Enemy()
{
    for (auto bullet : bullets_) {
        delete bullet;
    }
    bullets_.clear();
}

//������
void Enemy::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);

    /*transform_.position_.x = (float)(rand() % 401 - 200) / 10;//rand() %�͈�+�ŏ��l;
    transform_.position_.y = 15.0f;
    transform_.position_.z = 0.0f;*/

    transform_.scale_ = XMFLOAT3(1.0f, 1.0f, 0.5f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
    AddCollider(collision);

    //timeSinceLastShot_ = -initialDelay_;

}

//�X�V
void Enemy::Update()
{
    timeSinceLastShot_ += 1.0f / 60.0f; // ����: �Q�[����60FPS�œ��삵�Ă���
    if (timeSinceLastShot_ >= fireRate_) {
        // �e�𔭎˂��郍�W�b�N
        //auto bullet = new Bullet(this);
        //XMFLOAT3 bulletDirection = XMFLOAT3(0, -1, 0); // �������ɔ���
        //bullet->Initialize(transform_.position_, bulletDirection);
        //bullet->Initialize(/*transform_.position_, XMFLOAT3(0, -1, 0)*/);
        // �e�̈ʒu������̐ݒ�ȂǁA�K�v�ɉ�����Bullet�C���X�^���X�̐ݒ���s��
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
    auto bullet = new EnemyBullet(this); // �e�̃C���X�^���X�𐶐�


    DirectX::XMFLOAT3 direction = { 0.0f, -1.0f, 0.0f }; // ������

    // ���x��ݒ�
    float speed = 0.28f;

    bullet->Initialize(); // Bullet�̏�����
    
    DirectX::XMFLOAT3 bulletStartPosition = this->transform_.position_;
    bulletStartPosition.y -= 3.0f;
    bulletStartPosition.z = this->transform_.position_.z;

    bullet->SetPosition(bulletStartPosition/*this->transform_.position_*/);
    bullet->SetDirection(direction/*bulletDirection*/); // ������ݒ�
    bullet->SetSpeed(speed); // ���x��ݒ�

    bullets_.push_back(bullet); // �Ǘ����X�g�ɒǉ�
}

//�`��
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    for (auto& bullet : bullets_) {
        bullet->Draw();
    }
}

//�J��
void Enemy::Release()
{
}

//�����ɓ�������
void Enemy::OnCollision(GameObject* pTarget)
{
    //���������Ƃ��̏���   
    //�e�ɓ��������Ƃ�
    if (pTarget->GetObjectName() == "Bullet")
    {
        KillMe();
        pTarget->KillMe();
    }
}
