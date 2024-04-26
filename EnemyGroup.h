//#pragma once
//#include <vector>
//
//class EnemyGroup {
//public:
//    EnemyGroup(GameObject* parent);
//    ~EnemyGroup();
//
//    void Initialize();
//    void Update();
//    void Draw();
//    void Release();
//    int Count() const;
//
//    void CheckCollisions();
//
//private:
//    std::vector<Enemy*> enemies_;
//    GameObject* parent_;
//    bool directionRight = true;  // 敵グループの移動方向管理フラグ
//    float edgeLeft = -150.0f;    // 左端
//    float edgeRight = 150.0f;    // 右端
//    
//    
//};