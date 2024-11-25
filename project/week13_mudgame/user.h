#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
public:
    virtual ~User() = default;                // 가상 소멸자
    virtual void DecreaseHP(int dec_hp) = 0;  // HP 감소
    virtual void IncreaseHP(int inc_hp) = 0;  // HP 증가
    virtual int GetHP() const = 0;            // 현재 HP 반환
    virtual void AddItem() = 0;               // 아이템 추가
    virtual int GetItemCount() const = 0;     // 아이템 개수 반환
    virtual void DoAttack() = 0;              // 기본 공격
    virtual void PrintStatus() const = 0;     // 상태 출력
};

class Magician : public User {
private:
    int hp;
    int itemCnt;

public:
    Magician();                               // 생성자
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    int GetHP() const override;
    void AddItem() override;
    int GetItemCount() const override;
    void DoAttack() override;
    void PrintStatus() const override;
};

class Warrior : public User {
private:
    int hp;
    int itemCnt;

public:
    Warrior();                                // 생성자
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    int GetHP() const override;
    void AddItem() override;
    int GetItemCount() const override;
    void DoAttack() override;
    void PrintStatus() const override;
};

#endif
