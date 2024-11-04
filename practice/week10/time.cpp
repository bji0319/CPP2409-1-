#include <iostream>
using namespace std;

class Time {
private:
    int hour; // 0-23
    int minute; // 0-59

public:
    // 생성자
    Time(int h = 0, int m = 0) {
        hour = h;
        minute = m;
    }

    // 시간 증가 메서드
    void IncHour() {
        ++hour;
        if (hour > 23) hour = 0;
    }

    // 시간 설정 메서드
    void SetHour(int h) {
        if (h >= 0 && h < 24) hour = h;
        else cout << "Invalid hour!" << endl;
    }

    // 분 설정 메서드
    void SetMinute(int m) {
        if (m >= 0 && m < 60) minute = m;
        else cout << "Invalid minute!" << endl;
    }

    int GetHour() const {
        return hour;
    }

    int GetMinute() const {
        return minute;
    }

    void Print() const {
        cout << hour << ":" << (minute < 10 ? "0" : "") << minute << endl;
    }
};

int main() {
    Time a(0, 0); // 초기 시간 설정

    a.SetHour(6); // 시간 설정
    a.SetMinute(30); // 분 설정

    a.Print(); // 현재 시간 출력


    return 0;
}