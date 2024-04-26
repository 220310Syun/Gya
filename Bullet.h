#pragma once
#include "Engine/GameObject.h"
#include "Engine/SphereCollider.h"
#include <DirectXMath.h>
using namespace DirectX;

//弾を管理するクラス
class Bullet : public GameObject
{
    int hModel_;    //モデル番号
    XMFLOAT3 velocity;
public:
    //コンストラクタ
    Bullet(GameObject* parent);

    //デストラクタ
    virtual~Bullet();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetDirection(const DirectX::XMFLOAT3& direction);

    void SetPosition(const DirectX::XMFLOAT3& position);
   
    void SetSpeed(float speed);
};