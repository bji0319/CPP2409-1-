#include <iostream>
#include <string>
#include <vector>
#include "user.h" // User, Magician, Warrior 클래스 정의 포함
using namespace std;

// 함수 선언
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkState(vector<vector<int>> map, int user_x, int user_y, User& user);

const int mapX = 5;
const int mapY = 5;

int main() {
    vector<vector<int>> map = { {0, 1, 2, 0, 4},
                                {1, 0, 0, 2, 0},
                                {0, 0, 0, 0, 0},
                                {0, 2, 3, 0, 0},
                                {3, 0, 0, 0, 2} };

    // 직업 선택
    User* player = nullptr;
    cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        player = new Magician();
        cout << "Magician을 선택했습니다." << endl;
    } else if (choice == 2) {
        player = new Warrior();
        cout << "Warrior를 선택했습니다." << endl;
    } else {
        cout << "잘못된 선택입니다. 프로그램을 종료합니다." << endl;
        return 1;
    }

    // 초기 위치 설정
    int user_x = 0;
    int user_y = 0;

    cout << "게임을 시작합니다!" << endl;

    while (true) {
        string user_input;
        player->PrintStatus(); // 상태 출력

        cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,공격,종료): ";
        cin >> user_input;

        if (user_input == "상") {
            user_y -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            } else {
                cout << "위로 한 칸 올라갑니다." << endl;
                checkState(map, user_x, user_y, *player);
                player->DecreaseHP(1); // 이동 시 HP 감소
            }
        } else if (user_input == "하") {
            user_y += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            } else {
                cout << "아래로 한 칸 내려갑니다." << endl;
                checkState(map, user_x, user_y, *player);
                player->DecreaseHP(1);
            }
        } else if (user_input == "좌") {
            user_x -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            } else {
                cout << "왼쪽으로 이동합니다." << endl;
                checkState(map, user_x, user_y, *player);
                player->DecreaseHP(1);
            }
        } else if (user_input == "우") {
            user_x += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            } else {
                cout << "오른쪽으로 이동합니다." << endl;
                checkState(map, user_x, user_y, *player);
                player->DecreaseHP(1);
            }
        } else if (user_input == "지도") {
            displayMap(map, user_x, user_y);
        } else if (user_input == "정보") {
            player->PrintStatus();
        } else if (user_input == "공격") {
            player->DoAttack();
        } else if (user_input == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }

        if (player->GetHP() <= 0) {
            cout << "HP가 0이 되어 게임에서 패배했습니다." << endl;
            break;
        }
    }

    delete player; // 동적 할당 해제
    return 0;
}

// 함수 구현
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
        cout << "아이템을 발견했습니다!" << endl;
        user.AddItem();
    } else if (posState == 2) {
        cout << "적을 만났습니다! HP가 2 감소합니다." << endl;
        user.DecreaseHP(2);
    } else if (posState == 3) {
        cout << "포션을 발견했습니다! HP가 2 증가합니다." << endl;
        user.IncreaseHP(2);
    }
}
