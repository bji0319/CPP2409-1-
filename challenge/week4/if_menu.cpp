#include <iostream>>
using namespace std;

int main() {
  int choice;

  cout << "1. 파일 저장" << endl;
  cout << "2. 저장 없이 닫기" << endl;
  cout << "3. 종료" << endl;
  cin >> choice;

  if(choice == 1){
   cout << " 파일 저장을 선택했습니다." << endl;
  }else if(choice == 2){
   cout << " 저장 없이 닫기를 선택했습니다." << endl;
  }else{
   cout << " 종료를 선택했습니다" << endl;
  }
   return 0;
}