#include <iostream>>
using namespace std;

int main() {

int num1, num2, num3;

    cout << "첫 번째 정수를 입력하시오: ";
    cin >> num1;
    cout << "두 번째 정수를 입력하시오: ";
    cin >> num2;
    cout << "세 번째 정수를 입력하시오: ";
    cin >> num3;
   
   int max_number = num1;

   if (num2 > max_number) {
    max_number+ num2;
   }
   if(num3> max_number) {
    max_number = num3;
   }

   cout << "가자 큰 수는 :" <<
   max_number << endl;
   return 0;
   }