#include "EnemyBullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Bullet.h"
#include "Engine/SceneManager.h"
#include "Player.h"

// �R���X�g���N�^
EnemyBullet::EnemyBullet(GameObject* parent)
    : GameObject(parent, "EnemyBullet"), hModel_(-1), velocity(XMFLOAT3(0, 0, 0))
{
}

EnemyBullet::~EnemyBullet()
{
}

// ������
void EnemyBullet::Initialize()
{
    hModel_ = Model::Load("EnemyBullet.fbx");
    assert(hModel_ >= 0);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
    AddCollider(collision);

    velocity = XMFLOAT3(0, -15.0f, 0);
}

// �X�V
void EnemyBullet::Update()
{
    transform_.position_.x += velocity.x;
    transform_.position_.y += velocity.y;
    transform_.position_.z += velocity.z;

    // ��ʊO�ɏo����폜
    if (transform_.position_.z > 50.0f || transform_.position_.z < -50.0f ||
        transform_.position_.x > 50.0f || transform_.position_.x < -50.0f ||
        transform_.position_.y > 50.0f || transform_.position_.y < -50.0f)
    {
        KillMe();
    }
}

// �`��
void EnemyBullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

// �J��
void EnemyBullet::Release()
{
}

// �e�̕�����ݒ�
void EnemyBullet::SetDirection(const XMFLOAT3& direction) {
    velocity = direction;
}

// �e�̑��x��ݒ�
void EnemyBullet::SetSpeed(float speed) {
    DirectX::XMVECTOR dir = DirectX::XMLoadFloat3(&velocity);
    dir = DirectX::XMVector3Normalize(dir); // �����x�N�g���𐳋K��
    dir = DirectX::XMVectorScale(dir, speed); // ���K�����ꂽ�����x�N�g���ɑ��x���|����
    DirectX::XMStoreFloat3(&velocity, dir); // ���ʂ� velocity �ɖ߂�
}

// �e�̈ʒu��ݒ�
void EnemyBullet::SetPosition(const XMFLOAT3& position) {
    this->transform_.position_ = position;
}

void EnemyBullet::OnCollision(GameObject* pTarget) {
    if (pTarget->GetObjectName() == "Player") {
        // �Փ˂����I�u�W�F�N�g���v���C���[�̏ꍇ�̏���
        SceneManager* sceneManager = (SceneManager*)FindObject("SceneManager");
        if (sceneManager) {
            sceneManager->ChangeScene(SCENE_ID_GAMEOVER);
            
    }
        KillMe();  // �e�̍폜
        pTarget->KillMe();  // �v���C���[�̍폜
    }
}