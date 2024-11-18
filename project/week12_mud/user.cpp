#include "user.h"
#include <iostream>
using namespace std;

// 생성자: 초기 HP와 itemCnt 설정
User::User() : hp(20), itemCnt(0) {}

// HP 감소 함수
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;  // HP가 음수로 내려가지 않도록 처리
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

// 출력 연산자 중복 정의
ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP: " << user.hp << " / 먹은 아이템 수: " << user.itemCnt;
    return os;
}