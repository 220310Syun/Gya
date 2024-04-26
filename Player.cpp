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

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Player.fbx");
    assert(hModel_ >= 0);

    transform_.position_.x = 0.0f; // X����-1
    transform_.position_.y = -15.0f; // Y����-1
    transform_.position_.z = 0.0f;

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0f);
    AddCollider(collision);
}

//�X�V
void Player::Update()
{ 

    if (Input::IsKey(DIK_RIGHT))
    {
        //���炩�̏���
        transform_.position_.x += 0.3f;
    }
    if (Input::IsKey(DIK_LEFT))
    {
        //���炩�̏���
        transform_.position_.x -= 0.3f;
    }
    if (Input::IsKeyDown(DIK_SPACE))
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent());
        //pBullet->SetPosition(transform_.position_);

        //DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(0, 1, 0); // ���K�����ꂽ�����x�N�g���i�^��j
        //pBullet->SetDirection(direction); // ������ݒ�

        //float speed = 0.6f; // ��]���鑬�x
        //pBullet->SetSpeed(speed);

        XMFLOAT3 bulletStartPosition = transform_.position_;
        bulletStartPosition.y += 1.5;  // Y�������ɓK���ȋ������I�t�Z�b�g
        pBullet->SetPosition(bulletStartPosition);
        DirectX::XMFLOAT3 direction = DirectX::XMFLOAT3(0, 1, 0); // �����
        pBullet->SetDirection(direction);
        pBullet->SetSpeed(0.6f);
    }
    
    //Debug::Log("Player position: X=" + std::to_string(transform_.position_.x) + ", Y=" + std::to_string(transform_.position_.y) + ", Z=" + std::to_string(transform_.position_.z));
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
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
            pSceneManager->ChangeScene(SCENE_ID_GAMEOVER); // �Q�[���I�[�o�[�V�[���֐؂�ւ�
        }
        KillMe();  // �v���C���[���폜
        pTarget->KillMe();  // �e���폜
    }
}

//    if (pTarget->GetObjectName() == "Bullet") {
//        if (pTarget->GetParent() != this) {  // ���g�����˂����e�łȂ����Ƃ��m�F
//            SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
//            if (pSceneManager != nullptr) {
//                pSceneManager->ChangeScene(SCENE_ID_GAMEOVER); // �Q�[���I�[�o�[�V�[���֐؂�ւ�
//            }
//            KillMe();  // �v���C���[���폜
//            pTarget->KillMe();  // �e���폜
//        }
//    }
//}