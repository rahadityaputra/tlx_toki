#include <iostream>
using namespace std;


void solution(long long N, int x) {
 
  string result = "";
  while(N != 0) {
    int p = N % x;
    result += to_string(p);
    N = N / x;
  }

  reverse(result.begin(), result.end());

  cout << result << endl;

}

int main () {

long long N;
int x;

cin >> N >> x;


solution(N, x);




}
