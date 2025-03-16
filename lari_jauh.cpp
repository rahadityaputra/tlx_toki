#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int N, K;
vector<unsigned int> jarak_patok;
vector<unsigned int> bebek;

auto cari(unsigned int x) {
  
  
  auto hasil = upper_bound(jarak_patok.begin(), jarak_patok.end(), x);

  // if (*hasil == x)
  // {
  //   return (hasil - jarak_patok.begin());
  // }

  return (hasil - jarak_patok.begin());
  
}



void solution() {
  for (const auto& x: bebek) {
    if (x >= jarak_patok[N - 1])
    {
          cout <<  N << endl;
    } else if (x < jarak_patok[0])
    {
      cout <<  0 <<endl;
    } else {
      cout << cari(x) << endl;
    }
   }
}



int main () {
  cin >> N;
  cin >> K;

 unsigned int init = 0;
 for (unsigned int i = 0; i < N; i++) {
   unsigned int Ai;
   cin >> Ai;
    init += Ai; 
   jarak_patok.push_back(init);
 }



 for (unsigned int i = 0; i < K; i++) {
    unsigned int x;
    cin >> x;
    bebek.push_back(x);
 }

 solution();
}

