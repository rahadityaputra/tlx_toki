#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

float number[101];
long long N;

void solution () {
  float result;
 if (N % 2 == 1) {
   int count = 0;
   for (int i = 0; i < 101; i++) {
     count += number[i];
     if (count >= (N / 2) + 1) {
       result = i;
       break;
     }
   }
 } else {
   int count = 0;
    for (int i = 0; i < 101; i++) {
     count += number[i];
      if (count >= (N / 2)) {
        result = i;
        break;
       }
     }

     count = 0;
    for (int i = 0; i < 101; i++) {
      count += number[i];
      if (count >= (N / 2) + 1) {
        result += i;
        break;
       }
    }

    result = result / 2;

 }

  cout <<fixed << setprecision(1) << result << endl;

}


int main (int argc, char *argv[]) {

  memset(number, 0, sizeof(number));

  cin >> N;
  for (long long  i = 0; i < N; i++) {
    int A;
    cin >> A;
    number[A] = number[A] + 1;
  }
  solution();

  return 0;
}
