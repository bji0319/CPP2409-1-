#include "user.h"
#include <iostream>
using namespace std;

// User 클래스 구현
User::User(int playerID) : hp(20), itemCnt(0), id(playerID) {}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() const {
    return hp;
}

void User::AddItem() {
    itemCnt++;
}

int User::GetItemCount() const {
    return itemCnt;
}

void User::DoAttack() {
    cout << "공격합니다!" << endl;
}

int User::GetID() const {
    return id;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP: " << user.hp << " / 먹은 아이템 수: " << user.itemCnt;
    return os;
}

// Magician 클래스 구현
Magician::Magician(int playerID) : User(playerID) {}

void Magician::DoAttack() {
    cout << "마법 사용!" << endl;
}

// Warrior 클래스 구현
Warrior::Warrior(int playerID) : User(playerID) {}

void Warrior::DoAttack() {
    cout << "베기 사용!" << endl;
}
