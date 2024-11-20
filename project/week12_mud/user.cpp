#include "user.h"
#include <iostream>
using namespace std;

// User 클래스 구현
User::User() : hp(20), itemCnt(0) {}

// HP 감소 함수
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;
}

// HP 증가 함수
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

// 현재 HP 반환
int User::GetHP() const {
    return hp;
}

// 아이템 획득 시 호출
void User::AddItem() {
    itemCnt++;
}

// 현재 아이템 개수 반환
int User::GetItemCount() const {
    return itemCnt;
}

void User::DoAttack() {
    cout << "공격합니다!" << endl;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP: " << user.hp << " / 먹은 아이템 수: " << user.itemCnt;
    return os;
}

// Magician 공격 구현
void Magician::DoAttack() {
    cout << "마법 사용!" << endl;
}

// Warrior 공격 구현
void Warrior::DoAttack() {
    cout << "베기 사용!" << endl;
}

