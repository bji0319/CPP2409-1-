#include <iostream>
using namespace std;

int main() {
    const int numCell = 3; 
    char board[numCell][numCell]; // 보드판 배열
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수
    char currentUser = 'X'; // 첫 번째 유저는 'X'
    int k = 0; // 차례 카운터

    // 보드판 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임 시작
    while (true) {
        // 1. 누가 차례인지 출력
        switch (k % 2) {
            case 0:
                cout << "첫번째 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell || board[x][y] != ' ') {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 추가
        board[x][y] = currentUser;

        // 5. 현재 보드 출력
        for (int i = 0; i < numCell; i++) {
            cout << "----" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----" << endl;

        // 6. 빙고 체크 (가로, 세로, 대각선)
        int winner = 0;

        // 가로 체크
        for (int i = 0; i < numCell; i++) {
            if (board[x][i] != currentUser) break;
            if (i == numCell - 1) winner = 1;
        }

        // 세로 체크
        for (int i = 0; i < numCell; i++) {
            if (board[i][y] != currentUser) break;
            if (i == numCell - 1) winner = 1;
        }

        // 대각선 체크 (왼쪽 위에서 오른쪽 아래)
        if (x == y) {
            for (int i = 0; i < numCell; i++) {
                if (board[i][i] != currentUser) break;
                if (i == numCell - 1) winner = 1;
            }
        }

        // 대각선 체크 (오른쪽 위에서 왼쪽 아래)
        if (x + y == numCell - 1) {
            for (int i = 0; i < numCell; i++) {
                if (board[i][numCell - 1 - i] != currentUser) break;
                if (i == numCell - 1) winner = 1;
            }
        }

        // 승자가 있을 경우 출력하고 게임 종료
        if (winner == 1) {
            cout << "승리자: " << currentUser << endl;
            break;
        }

        // 7. 보드가 꽉 찼는지 확인
        int isFull = 1; // 꽉 찼음을 의미하는 변수
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    isFull = 0;
                     break;
                }
            }
            if (isFull == 0) break;
        }

        if (isFull == 1) {
            cout << "보드가 꽉 찼습니다!" << endl;
            break;
        }

        // 8. 차례 교체
        k++;
    }

    return 0;
}