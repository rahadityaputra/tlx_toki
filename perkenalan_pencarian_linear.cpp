#include <iostream>
#include <vector>

using namespace std;

int N;
long long X;


int main (int argc, char *argv[]) {

 cin >> N >> X;

 long long result;
 for (int i = 0; i < N; i++) {
   long long A;
   cin >> A;
  if(i == 0) {
    result = A;
    continue;
  }
  
  if (abs(X - result) > abs(X - A)) {
   result = A;
  } else if (abs(X - result) == abs(X - A)) {
    if(result > A) {
      result = A;
    }
  }


   
 }

  cout << result << endl;
  return 0;
}
