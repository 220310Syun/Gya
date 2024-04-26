#pragma once
#include "Engine/GameObject.h"
#include "Engine/SphereCollider.h"
#include <DirectXMath.h>
using namespace DirectX;

//�e���Ǘ�����N���X
class Bullet : public GameObject
{
    int hModel_;    //���f���ԍ�
    XMFLOAT3 velocity;
public:
    //�R���X�g���N�^
    Bullet(GameObject* parent);

    //�f�X�g���N�^
    virtual~Bullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetDirection(const DirectX::XMFLOAT3& direction);

    void SetPosition(const DirectX::XMFLOAT3& position);
   
    void SetSpeed(float speed);
};