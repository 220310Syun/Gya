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
//    float spacing = 2.5f; // �G�Ԃ̊Ԋu
//    int rows = 3; // 3��̓G
//
//    for (int row = 0; row < rows; ++row) {
//        float y = 15.0f - row * 5.0f; // �s���Ƃ̍�������
//        for (int i = 0; i < numEnemiesPerRow; ++i) {
//            Enemy* enemy = new Enemy(parent_);
//            enemy->Initialize();
//            float x = i * spacing - (numEnemiesPerRow / 2) * spacing; // �G�̈ʒu����
//            float z = 0.0f;
//            enemy->SetPosition(XMFLOAT3(x, y, z));
//            enemies_.push_back(enemy);
//        }
//    }
//}
//
//void EnemyGroup::Update() {
//    float moveStep = 0.1f; // �ړ���
//
//    static bool moveRight = true; // �ړ������t���O
//
//
//
//    for (auto& enemy : enemies_) {
//        enemy->Update(); // �e�G�̍X�V
//
//        // �G�O���[�v�̉��ړ��𒲐�
//        XMFLOAT3 pos = enemy->GetPosition();
//        if (moveRight) {
//            pos.x += moveStep;
//            if (pos.x > 150.0f) { // �E�[�ɒB�����ꍇ
//                moveRight = false;
//            }
//        }
//        else {
//            pos.x -= moveStep;
//            if (pos.x < -150.0f) { // ���[�ɒB�����ꍇ
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
//    // �����ŕK�v�ȃ����[�X���������s
//}
//
//int EnemyGroup::Count() const {
//    return enemies_.size(); // �G���X�g�̃T�C�Y��Ԃ�
//}