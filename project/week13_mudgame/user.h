#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
protected:
    int hp;
    int itemCnt;

public:
    User();                         // 생성자
    void DecreaseHP(int dec_hp);    // HP 감소
    void IncreaseHP(int inc_hp);    // HP 증가
    int GetHP() const;              // 현재 HP 반환
    void AddItem();                 // 아이템 추가
    int GetItemCount() const;       // 아이템 개수 반환
    void DoAttack();                // 기본 공격 함수 (재정의하지 않음)

    // 출력 연산자 중복 정의
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

class Magician : public User {
public:
    void DoAttack();  // Magician만의 공격 함수
};

class Warrior : public User {
public:
    void DoAttack();  // Warrior만의 공격 함수
};

#endif

