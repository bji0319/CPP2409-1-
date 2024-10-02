#include <iostream>
using namespace std;

#define WIDTH 9
#define HEIGHt 3

int main() {
    int table [HEIGHt] [WIDTH];
    int r, c;

    for ( r= 0; r< HEIGHt; r++ )
    for ( c= 0; c< WIDTH; c++)
    table[r][c] = (r +1)*(c+1);

    for ( r= 0; r< HEIGHt; r++ ) {
    for ( c= 0; c< WIDTH; c++) {
       cout << table[r][c] << ","; 
}
cout << endl;
}

}