#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> p;

  int coins[] = {1000, 500, 200, 100, 50, 20, 10, 5, 1};
  int kembalian;

void solution() {
  int x = 0;
  while (kembalian > 0) {
   if (kembalian - coins[x] >= 0) {
     if (p.count(coins[x])) {
       p[coins[x]] = p[coins[x]] + 1;
     } else {
       p[coins[x]] = 1;
     }
      kembalian = kembalian - coins[x];
    } else {
      x++;
    }
  }
}


void cetakKembalian() {
  for(const auto& i : p) {
    cout << "Koin " << i.first << " dipakai " << i.second << " x." << endl;
  }
}



int main () {
  cin >> kembalian;
  solution();
  cetakKembalian();
}
