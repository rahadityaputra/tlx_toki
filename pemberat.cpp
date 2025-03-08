#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

vector<long long> A;

void solution(long long B, long long K) {
  int count = log(K) / log(2);

  for(int i = count; i >= 0; i--) {
    if(K - pow(2, i) >= B ) {
      A.push_back(pow(2, i));
      K = K - pow(2, i);
    }
    if(K == B) break;
  }



  for(int i = 0; i < A.size(); i++) {
    cout << A[i] << endl;

  }
  

}

int main() {
  long long B, K;

  cin >> B >> K;

  solution(B, K);
} 
