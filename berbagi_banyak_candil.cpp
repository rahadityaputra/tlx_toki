#include <iostream>
#include <vector>

using namespace std;
void solution(long long B, long long C, long long D){
  long long count = 0;
  long long diff = C - D;
  vector<long long>result;
  if(C == D) {
   if (B - C < 0) { 
    cout << 0 << endl; 
    return;
  }
    cout << B - C << endl;
    return;
  }

  for (long long i = 1; i * i <= diff; i++) {
    if (diff % i == 0) { 
      if (i <= B) result.push_back(i);
      if ((diff / i) <= B && i != (diff / i)) result.push_back(diff / i);
    }
  }


  for (long long i = 0; i < result.size(); i++) {
    if (result[i] > D) {
      count++;
    }
  }


  cout << count << endl;
}


int main () {
  long long B, C, D;
  cin >> B >> C >> D;

  solution(B, C, D);
}


