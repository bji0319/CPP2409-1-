#include <iostream>
using namespace std;

// 입력 받은 좌표의 유효성 체크
bool isValid(int x, int y, char board[][5], int numCell) {
    if (x < 0 || y < 0 || x >= numCell || y >= numCell) { // 좌표 범위를 벗어날 때
        cout << x << "," << y << ": x와 y 둘 중 하나가 칸을 벗어납니다. " << endl;
        return false;
    }
    if (board[x][y] != ' ') { // 좌표범위의 입력값이 중복될 때
        cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
        return false;
    }
    return true;
}

// 승자 체크 코드
bool checkWin(char currentUser, char board[][5], int numCell) {
    // 가로/세로 돌 체크하기
    for (int i = 0; i < numCell; i++) {
        if ((board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser && board[i][3] == currentUser && board[i][4] == currentUser) ||
            (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser && board[3][i] == currentUser && board[4][i] == currentUser)) {
            return true;
        }
    }
    // 대각선 체크하기
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) {
            diag1 = false; // 왼쪽 위에서 오른쪽 아래 대각선
        }
        if (board[i][numCell - 1 - i] != currentUser) {
            diag2 = false; // 오른쪽 위에서 왼쪽 아래 대각선
        }
    }
    return diag1 || diag2;
}
int main() {
    const int numCell = 5; // 보드판의 가로 세로 길이
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char players[3] = {'X', 'O', 'Y'}; // 3명의 플레이어
    char currentUser; // 현재 유저의 돌을 저장하기 위한 변수
    char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
    int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

    // 보드판 초기화
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    // 게임을 무한 반복
    while (true) {
        // 1. 누구 차례인지 출력
        currentUser = players[k % 3]; // 3인용 차례
        cout << (k % 3 + 1) << "번 유저(" << currentUser << ")의 차례입니다. -> ";

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (!isValid(x, y, board, numCell)) {
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j < numCell - 1) {
                    cout << "  |";
                }
            }
            cout << endl;
        }
        cout << "---|---|---|---|---" << endl;

        // 승리 여부 체크
        if (checkWin(currentUser, board, numCell)) {
            cout << (k % 3 + 1) << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

        // 모든 칸 다 찼는지 체크하기
        bool isDraw = true; // 무승부 체크
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    isDraw = false; // 빈 칸이 있으면 무승부가 아님
                    break;
                }
            }
        }
        if (isDraw) {
            cout << "모든 칸이 다 찼습니다. 무승부입니다!" << endl;
            break;
        }

        k++; // 차례를 진행
    }

    return 0;
}
