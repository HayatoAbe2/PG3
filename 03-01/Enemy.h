#pragma once
class Enemy {
public:
    void Update();

    void Approach();
    void Attack();
    void Away();
private:
    static void (Enemy::* pFuncTable[])();
    int phase_ = 0;
};

