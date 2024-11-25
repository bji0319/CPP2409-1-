#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
protected:
    int hp;
    int itemCnt;
    int id;  // 사용자 ID

public:
    User(int playerID);             // 생성자
    void DecreaseHP(int dec_hp);    // HP 감소
    void IncreaseHP(int inc_hp);    // HP 증가
    int GetHP() const;              // 현재 HP 반환
    void AddItem();                 // 아이템 추가
    int GetItemCount() const;       // 아이템 개수 반환
    virtual void DoAttack();        // 기본 공격 함수 (가상 함수로 설정)

    int GetID() const;              // 사용자 ID 반환
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    virtual ~User() = default;      // 가상 소멸자
};

class Magician : public User {
public:
    Magician(int playerID);          // 생성자
    void DoAttack() override;       // Magician만의 공격 함수
};

class Warrior : public User {
public:
    Warrior(int playerID);           // 생성자
    void DoAttack() override;       // Warrior만의 공격 함수
};

#endif
