#include <iostream>
#include <string>
using namespace std;

// 소문자로 변환함수
string toLowerStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// 대문자로 변환 함수
string toUpperStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// 해밍 거리를 계산하는 함수
int calcHammingDist(string s1, string s2) {
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);
   
    int count = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    string s1, s2;
    int count = 0;
   
   
    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;

    if (s1.length() != s2.length()) 
            cout << "오류: 길이가 다름." << endl;
    else {
            int count = calcHammingDist(s1,s2);
            cout << "해밍 거리는 " << count << endl;
          
        }
    

    return 0;
}