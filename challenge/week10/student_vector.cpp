#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;
    int score;
    
    cout << "성적을 입력하시오(종료는 -1) :" << score << endl;

    cin >> score;

    while(true) {
        cin >> score;
        if (score == -1)
        break;
        scores.push_back(score);
        
    }

    int sum = 0;
    for (int s : scores) {
        sum += s;
    }
   
    double average = static_cast<double>(sum) / scores.size();
    cout << "성적 평균 = " << average << endl;

    return 0;
}
