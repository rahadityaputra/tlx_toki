#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


vector<pair<int, int>> aktivitas;
vector<pair<int, int>> aktivitasYangDipilih;

void aktivitasDipilih() {
  for(auto &i : aktivitasYangDipilih) {
    cout << i.first << " - " << i.second << endl;
  }
}

void urutkanJamAktivitas() {
  sort(aktivitas.begin(), aktivitas.end(), [](auto &a, auto& b) {
      return a.second < b.second;
      });
}

void pilihAktivitas() {
  int selesai = -1;

  for(auto &i : aktivitas) {
   if (i.first >= selesai) {
      selesai = i.second;
      aktivitasYangDipilih.push_back({i.first, i.second});
    } 
  }
}

void solution() {
  urutkanJamAktivitas();
  pilihAktivitas();
  aktivitasDipilih();
}

int main (int argc, char *argv[]) {
  string lanjut;
  while (true) {
    int mulai, selesai;
    cin >> mulai >> selesai;
    
    aktivitas.push_back({mulai, selesai});
    
    cout << "Lanjut input ?  = " ;
    cin >> lanjut;

    if (lanjut == "n") {
      cout << "input aktivitas selesai" << endl;
     break; 
    } else {
      cout << "input dilanjutkan" << endl;
    }
       
  }   
  solution();

    return 0;
}
