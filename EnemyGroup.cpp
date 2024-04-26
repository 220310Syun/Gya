//#include "EnemyGroup.h"
//
//EnemyGroup::EnemyGroup(GameObject* parent) : parent_(parent) {}
//
//EnemyGroup::~EnemyGroup() {
//    for (auto enemy : enemies_) {
//        delete enemy;
//    }
//    enemies_.clear();
//}
//
//void EnemyGroup::Initialize() {
//    int numEnemiesPerRow = 10;
//    float spacing = 2.5f; // 敵間の間隔
//    int rows = 3; // 3列の敵
//
//    for (int row = 0; row < rows; ++row) {
//        float y = 15.0f - row * 5.0f; // 行ごとの高さ調整
//        for (int i = 0; i < numEnemiesPerRow; ++i) {
//            Enemy* enemy = new Enemy(parent_);
//            enemy->Initialize();
//            float x = i * spacing - (numEnemiesPerRow / 2) * spacing; // 敵の位置調整
//            float z = 0.0f;
//            enemy->SetPosition(XMFLOAT3(x, y, z));
//            enemies_.push_back(enemy);
//        }
//    }
//}
//
//void EnemyGroup::Update() {
//    float moveStep = 0.1f; // 移動量
//
//    static bool moveRight = true; // 移動方向フラグ
//
//
//
//    for (auto& enemy : enemies_) {
//        enemy->Update(); // 各敵の更新
//
//        // 敵グループの横移動を調整
//        XMFLOAT3 pos = enemy->GetPosition();
//        if (moveRight) {
//            pos.x += moveStep;
//            if (pos.x > 150.0f) { // 右端に達した場合
//                moveRight = false;
//            }
//        }
//        else {
//            pos.x -= moveStep;
//            if (pos.x < -150.0f) { // 左端に達した場合
//                moveRight = true;
//            }
//        }
//        enemy->SetPosition(pos);
//        //CheckCollisions();
//    }
//}
//
//void EnemyGroup::Draw() {
//    for (auto& enemy : enemies_) {
//        enemy->Draw();
//    }
//}
//
//void EnemyGroup::Release() {
//    // ここで必要なリリース処理を実行
//}
//
//int EnemyGroup::Count() const {
//    return enemies_.size(); // 敵リストのサイズを返す
//}