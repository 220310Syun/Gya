#pragma once
#include "Engine/GameObject.h"
//#include "Bullet.h"
#include <vector>
#include <cstdlib>  // std::rand と std::srand を使用するために必要
#include <ctime> 
#include "EnemyBullet.h"

//◆◆◆を管理するクラス
class Enemy : public GameObject
{
    int hModel_;  //モデル番号
    bool i = 0;
    float fireRate_; // 2秒ごとに弾を発射 = 2.0f
    float timeSinceLastShot_;

    float initialDelay_;
    
    std::vector<EnemyBullet*> bullets_;

    void FireBullet();

public:
    //コンストラクタ
    Enemy(GameObject* parent);

    //デストラクタ
    virtual ~Enemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;
    
    //DirectX::XMFLOAT3 GetPlayerPosition();

};
