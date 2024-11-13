#include <iostream>
#include <string>
using namespace std;

class Date {
    int year, month, day;
public:
    // 생성자
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    // 출력 함수
    void Print() const {
        cout << year << "." << month << "." << day << endl;
    }
};

class Person {
    string name;
    Date birth;
public:
    // 생성자
    Person(string n, Date d) : name(n), birth(d) {}
    
    // 출력 함수
    void Print() const {
        cout << name << ": ";
        birth.Print();
        cout << endl;
    }
};

int main() {
    Date d{ 1998, 3, 1 };  // Date 객체 생성
    Person p{"김철수", d};  // Person 객체 생성 (Date 객체 전달)
    p.Print();  // 출력
    return 0;
}
