#pragma once
#include "Engine/GameObject.h"
//#include "Bullet.h"
#include <vector>
#include <cstdlib>  // std::rand �� std::srand ���g�p���邽�߂ɕK�v
#include <ctime> 
#include "EnemyBullet.h"

//���������Ǘ�����N���X
class Enemy : public GameObject
{
    int hModel_;  //���f���ԍ�
    bool i = 0;
    float fireRate_; // 2�b���Ƃɒe�𔭎� = 2.0f
    float timeSinceLastShot_;

    float initialDelay_;
    
    std::vector<EnemyBullet*> bullets_;

    void FireBullet();

public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    virtual ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
    
    //DirectX::XMFLOAT3 GetPlayerPosition();

};
