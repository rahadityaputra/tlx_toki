#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int N, Q;
vector<unsigned int>A;
vector<pair<unsigned int, unsigned int>> pertanyaan;

int cari(unsigned int x, unsigned int y) {
  auto awal = upper_bound(A.begin(), A.end(), x);
  auto akhir = upper_bound(A.begin(), A.end(), y);
  
  return akhir - awal;
}

void solution() {
  for (const auto& [x, y] : pertanyaan) {
   cout << cari(x, y) << endl;
  }

}

int main(){
 cin >> N;

 for (unsigned int i = 0; i < N; i++) {
   unsigned int Ai;
   cin >> Ai;
   A.push_back(Ai);
 }

 cin >> Q;

 for (unsigned int i = 0; i < Q; i++) {
    unsigned int x, y;
    cin >> x;
    cin >> y;
    pertanyaan.emplace_back(x,y);
 }


 solution();


}
