//kurang efisian dalam penggunakan waktu
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<float> number;
long long N;

void urutkan () {
  for(long long i = 0 ; i < N; i++) {
    for (long long j = 0; j < N; j++) {
      if (number[i] > number[j]) {
        float temp = number[i];
        number[i] = number[j];
        number[j] = temp;
      }
    }

  }
}

void solution () {
  urutkan();
  float result;
  if(N % 2 == 1) {
    result = (number[N / 2]); 
  } else {
    result = (number[(N / 2) - 1] + number[N / 2 ]) / 2;
  }
    cout <<fixed << setprecision(1) << result << endl;

}


int main (int argc, char *argv[]) {

  cin >> N;
  for (long long  i = 0; i < N; i++) {
    float A;
    cin >> A;
    number.push_back(A);
  }

  solution();

  return 0;
}
