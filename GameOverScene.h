#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"


//■■シーンを管理するクラス
class GameOverScene : public GameObject
{
	int hPict_;    //画像番号
	Text* pText;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameOverScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};
