#include <iostream>
#include <vector>

using namespace std;

vector<int>kartu;
int N;


void solution() {
  int count = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (kartu[j] > kartu[j+1]) {
        count++;
        int temp = kartu[j];
        kartu[j] = kartu[j+1];
        kartu[j+1] = temp;
      }
    }
  }

  cout << count << endl;

}

int main(){
 cin >> N;

 for (int i = 0; i < N; i++) {
   long long A;
   cin >> A;
   kartu.push_back(A);
 }

 solution();


}
