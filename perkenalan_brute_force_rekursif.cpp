#include  <iostream>
#include  <vector>
using namespace std;
vector<int>hasil;
int K, N, M;


void solution(int kedalaman) {
 if (kedalaman > K) {
   int total = 0;
   for (int i = 1; i <= K; i++) {
     total += hasil[i];
   }

   if (total <= M) {
    for (int i = 1; i <= K; i++) {
     cout << hasil[i] << " ";
    }
   cout << endl;
   }
  } else  {
    for (int i = hasil[kedalaman - 1] + 1; i <= N; i++) {
      hasil[kedalaman] = i;
      solution(kedalaman + 1);
    }
  } 
}

int main (int argc, char *argv[]) {
  hasil.push_back(0);
  cin >> N >> K >> M;

  solution(1);

       
}
