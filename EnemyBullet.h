#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include <DirectXMath.h>


using namespace DirectX;

//�����V�[�����Ǘ�����N���X
class EnemyBullet : public GameObject
{
    int hModel_;    // ���f���̃n���h��
    XMFLOAT3 velocity; // �e�̑��x�x�N�g��

public:
    // �R���X�g���N�^
    EnemyBullet(GameObject* parent);
    virtual ~EnemyBullet();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �`��
    void Draw() override;

    // �J��
    void Release() override;

    void OnCollision(GameObject* pTarget) override;
    
    // �e�̕����Ƒ��x��ݒ肷��֐�
    void SetDirection(const XMFLOAT3& direction);
    void SetSpeed(float speed);

    // �e�̈ʒu��ݒ肷��֐�
    void SetPosition(const XMFLOAT3& position);
};
