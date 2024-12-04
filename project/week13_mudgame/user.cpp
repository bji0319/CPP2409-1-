#include "user.h"
#include <iostream>
using namespace std;

// Magician 클래스 구현
Magician::Magician() : hp(20), itemCnt(0) {}

void Magician::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;
}

void Magician::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int Magician::GetHP() const {
    return hp;
}

void Magician::AddItem() {
    itemCnt++;
}

int Magician::GetItemCount() const {
    return itemCnt;
}

void Magician::DoAttack() {
    cout << "마법 사용!" << endl;
}

void Magician::PrintStatus() const {
    cout << "Magician 상태: HP = " << hp << ", 아이템 수 = " << itemCnt << endl;
}

// Warrior 클래스 구현
Warrior::Warrior() : hp(25), itemCnt(0) {}

void Warrior::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;
}

void Warrior::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int Warrior::GetHP() const {
    return hp;
}

void Warrior::AddItem() {
    itemCnt++;
}

int Warrior::GetItemCount() const {
    return itemCnt;
}

void Warrior::DoAttack() {
    cout << "베기 사용!" << endl;
}

void Warrior::PrintStatus() const {
    cout << "Warrior 상태: HP = " << hp << ", 아이템 수 = " << itemCnt << endl;
}