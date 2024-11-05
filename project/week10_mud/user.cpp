#include "user.h"

User::User() : hp(20) {}  // 초기 HP를 20으로 설정하는 생성자

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0;  // HP가 0 이하로 내려가지 않도록 처리
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() const {
    return hp;
}