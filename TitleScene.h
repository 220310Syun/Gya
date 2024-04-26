#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include <memory>

class TitleScene : public GameObject {
public:
    TitleScene(GameObject* parent);
    virtual ~TitleScene();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
private:
    int titleImageId_;
    Text* pText;

};
