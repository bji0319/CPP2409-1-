#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 5; // 5명으로 설정
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    int i = 0;
    while (i < maxPeople) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];

        if (ages[i] <= 0) {
            cout << "잘못된 나이 입력입니다. 프로그램을 종료합니다." << endl;
            return 0; 
        }
        i++;
    }

    
    int maxAge = ages[0];
    int minAge = ages[0];
    string oldestPerson = names[0];
    string youngestPerson = names[0];

    i = 1; 
    while (i < maxPeople) {
        if (ages[i] > maxAge) {
            maxAge = ages[i];
            oldestPerson = names[i];
        }
        if (ages[i] < minAge) {
            minAge = ages[i];
            youngestPerson = names[i];
        }
        i++;
    }

    // 
    int choice;
    while (true) {
        cout << "\n메뉴를 선택하세요:" << endl;
        cout << "1. 가장 나이 많은 사람 출력" << endl;
        cout << "2. 가장 나이 적은 사람 출력" << endl;
        cout << "3. 프로그램 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        if (choice == 1) {
            cout << "가장 나이 많은 사람: " << oldestPerson << " (" << maxAge << "세)" << endl;
        }
        else if (choice == 2) {
            cout << "가장 나이 적은 사람: " << youngestPerson << " (" << minAge << "세)" << endl;
        }
        else if (choice == 3) {
            cout << "프로그램을 종료." << endl;
            break; // 프로그램 종료
        }
        else {
            cout << "잘못된 선택입니다." << endl;
             break; // 프로그램 종료
        }
    }

    return 0;
}

    