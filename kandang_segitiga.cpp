#include <iostream>

using namespace std;

int x[17][17];

void comb() {
  for(int i = 0; i < 17; i++) {
      x[i][0] = x[i][i] = 1;

      for(int j = 1 ; j < i; j++) {
         x[i][j] = x[i - 1][j] + x[i - 1][j - 1];
      }
  }
}



int main(){
 comb();
 short int N;
 cin >> N;
 cout << x[N][3] << endl;

}

