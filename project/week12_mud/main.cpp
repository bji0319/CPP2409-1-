
#include <iostream>
#include <string>
#include <vector>
#include "user.h"  // User, Magician, Warrior 클래스 정의 포함
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkState(vector<vector<int>> map, int user_x, int user_y, User& user);

// 메인 함수
int main() {
    vector<vector<int>> map = { {0, 1, 2, 0, 4},
                                {1, 0, 0, 2, 0},
                                {0, 0, 0, 0, 0},
                                {0, 2, 3, 0, 0},
                                {3, 0, 0, 0, 2} };

    // Magician과 Warrior 객체 생성
    Magician magician;
    Warrior warrior;

    int user_x = 0;
    int user_y = 0;

    // 현재 플레이어를 관리하는 변수 (0: Magician, 1: Warrior)
    int currentPlayer = 0;

    cout << "Magician과 Warrior가 게임을 시작합니다!" << endl;

    while (1) {
        string user_input = "";

        // 현재 플레이어 출력
        if (currentPlayer == 0) {
            cout << "현재 플레이어: Magician" << endl;
            cout << "상태: " << magician << endl;
        } else {
            cout << "현재 플레이어: Warrior" << endl;
            cout << "상태: " << warrior << endl;
        }

        cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,공격,종료): ";
        cin >> user_input;

        User& activePlayer = (currentPlayer == 0) ? (User&)magician : (User&)warrior;

        if (user_input == "상") {
            user_y -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            } else {
                cout << "위로 한 칸 올라갑니다." << endl;
                checkState(map, user_x, user_y, activePlayer);  // 현재 플레이어로 상태 처리
                activePlayer.DecreaseHP(1);  // 이동 시 HP 감소
                displayMap(map, user_x, user_y);
            }
        }
        else if (user_input == "하") {
            user_y += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            } else {
                cout << "아래로 한 칸 내려갑니다." << endl;
                checkState(map, user_x, user_y, activePlayer);
                activePlayer.DecreaseHP(1);
                displayMap(map, user_x, user_y);
            }
        }
        else if (user_input == "좌") {
            user_x -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            } else {
                cout << "왼쪽으로 이동합니다." << endl;
                checkState(map, user_x, user_y, activePlayer);
                activePlayer.DecreaseHP(1);
                displayMap(map, user_x, user_y);
            }
        }
        else if (user_input == "우") {
            user_x += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            } else {
                cout << "오른쪽으로 이동합니다." << endl;
                checkState(map, user_x, user_y, activePlayer);
                activePlayer.DecreaseHP(1);
                displayMap(map, user_x, user_y);
            }
        }
        else if (user_input == "지도") {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "정보") {
            cout << "Magician 상태: " << magician << endl;
            cout << "Warrior 상태: " << warrior << endl;
        }
        else if (user_input == "공격") {
            if (currentPlayer == 0) {
                cout << "Magician의 공격 차례입니다." << endl;
                magician.DoAttack();
                warrior.DecreaseHP(5);
                cout << "Warrior의 상태: " << warrior << endl;

                if (warrior.GetHP() <= 0) {
                    cout << "Warrior가 쓰러졌습니다! Magician 승리!" << endl;
                    break;
                }
            } else {
                cout << "Warrior의 공격 차례입니다." << endl;
                warrior.DoAttack();
                magician.DecreaseHP(7);
                cout << "Magician의 상태: " << magician << endl;

                if (magician.GetHP() <= 0) {
                    cout << "Magician이 쓰러졌습니다! Warrior 승리!" << endl;
                    break;
                }
            }
        }
        else if (user_input == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        if (magician.GetHP() <= 0 || warrior.GetHP() <= 0) {
            cout << "게임 종료." << endl;
            break;
        }

        // 턴 교체
        if (currentPlayer == 0) {
            currentPlayer = 1; // Magician → Warrior
        } else {
            currentPlayer = 0; // Warrior → Magician
        }
    }

    return 0;
}

// 지도 표시 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                int posState = map[i][j];
                switch (posState) {
                case 0:
                    cout << "      |";
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |";
                    break;
                case 3:
                    cout << " 포션 |";
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

bool checkGoal(vector<vector<int>> map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

void checkState(vector<vector<int>> map, int user_x, int user_y, User& user) {
    int posState = map[user_y][user_x];
    if (posState == 1) {
        cout << "아이템이 있습니다." << endl;
        user.AddItem();
    } else if (posState == 2) {
        user.DecreaseHP(2);
        cout << "적을 만났습니다! HP가 2 감소합니다." << endl;
    } else if (posState == 3) {
        user.IncreaseHP(2);
        cout << "포션을 발견했습니다! HP가 2 증가합니다." << endl;
    }
}