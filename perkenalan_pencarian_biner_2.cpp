#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned int N, Q;
vector<unsigned int>A;
vector<unsigned int> pertanyaan;

auto cari(unsigned int x) {
  auto hasil = lower_bound(A.begin(), A.end(), x);
  return hasil - A.begin() + 1;
}

void solution() {
  for (const auto& x: pertanyaan) {
   cout << cari(x) << endl;
  }

}

int main(){
 cin >> N;
 unsigned int init = 0;
 for (unsigned int i = 0; i < N; i++) {
   unsigned int Ai;
   cin >> Ai;
    init += Ai; 
   A.push_back(init);
 }

 cin >> Q;

 for (unsigned int i = 0; i < Q; i++) {
    unsigned int x;
    cin >> x;
    pertanyaan.push_back(x);
 }

 solution();
}
