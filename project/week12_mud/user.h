#ifndef USER_H
#define USER_H

#include <iostream>

class User {
private:
    int hp;        // 체력
    int itemCnt;   // 먹은 아이템 수

public:
    User();                           // 생성자
    void DecreaseHP(int dec_hp);      // HP 감소 함수
    void IncreaseHP(int inc_hp);      // HP 증가 함수
    int GetHP() const;                // 현재 HP 반환 함수
    void AddItem();                   // 아이템 먹기 함수
    int GetItemCount() const;         // 아이템 개수 반환 함수

    // 출력 연산자 중복 정의
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif
