
#include <iostream>
#include <string>
#include "user.h"
#include <vector>
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

    User user;  // User 객체 생성
    int user_x = 0;
    int user_y = 0;

    while (1) {
        string user_input = "";
        cout << "현재 상태: " << user << endl; 
        cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,종료): ";
        cin >> user_input;

        if (user_input == "상") {
            user_y -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            } else {
                cout << "위로 한 칸 올라갑니다." << endl;
                checkState(map, user_x, user_y, user);
                user.DecreaseHP(1);
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
                checkState(map, user_x, user_y, user);
                user.DecreaseHP(1);
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
                checkState(map, user_x, user_y, user);
                user.DecreaseHP(1);
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
                checkState(map, user_x, user_y, user);
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
            }
        }
        else if (user_input == "지도") {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "정보") {
            cout << user << endl;
        }
        else if (user_input == "종료") {
            cout << "종료합니다." << endl;
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

        if (user.GetHP() <= 0) {
            cout << "실패: 체력이 0이 되었습니다." << endl;
            break;
        }
    }
    return 0;
}

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
