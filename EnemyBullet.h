#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include <DirectXMath.h>


using namespace DirectX;

//■■シーンを管理するクラス
class EnemyBullet : public GameObject
{
    int hModel_;    // モデルのハンドル
    XMFLOAT3 velocity; // 弾の速度ベクトル

public:
    // コンストラクタ
    EnemyBullet(GameObject* parent);
    virtual ~EnemyBullet();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 描画
    void Draw() override;

    // 開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;
    
    // 弾の方向と速度を設定する関数
    void SetDirection(const XMFLOAT3& direction);
    void SetSpeed(float speed);

    // 弾の位置を設定する関数
    void SetPosition(const XMFLOAT3& position);
};
