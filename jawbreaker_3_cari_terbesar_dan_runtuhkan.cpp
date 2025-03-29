#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> salinan;
vector<vector<int>> sudahDikunjungi;
vector<pair<int, int>> titikRuntuh;
int M, N, B, K;
 // masih salah ini bang, belum semua test case correct 

int xBesar = 0, yBesar = 0;
int T;
void klik(int x, int y, int warna){
  if (x < M && y < N && x >= 0 && y >= 0) {
    if (!sudahDikunjungi[x][y]) {
      if (arr[x][y] == warna) {
        T++;
        salinan[x][y] = 0;
        sudahDikunjungi[x][y] = true;
        klik(x+1, y, warna);
        klik(x-1, y, warna);
        klik(x, y+1, warna);
        klik(x, y-1, warna);
      } 
    }
  }
}

void klik2(int x, int y, int warna){
  if (x < M && y < N && x >= 0 && y >= 0) {
    if (!sudahDikunjungi[x][y]) {
      if (arr[x][y] == warna) {
        T++;
        titikRuntuh.push_back({x, y});
        sudahDikunjungi[x][y] = true;
        klik2(x+1, y, warna);
        klik2(x-1, y, warna);
        klik2(x, y+1, warna);
        klik2(x, y-1, warna);
      } 
    }
  }
}

void cetak() {
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                cout << ". ";
            } else {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
    
}

void runtuhkan() {
    for (int i = 0 ; i < titikRuntuh.size(); i++)
    {
        for (int j = titikRuntuh[i].first; j > 0; j--)
        {
            arr[j][titikRuntuh[i].second] = arr[j - 1][titikRuntuh[i].second]; 
        }
        arr[0][titikRuntuh[i].second] = 0;
    }
}

void solution() {
	int terbesar = 0;
	for (int i = 0; i < arr.size(); i++) {
	   for (int j = 0; j < arr[i].size(); j++) {
        if (salinan[i][j] != 0) 
        {
          klik(i, j, arr[i][j]);
  
          for (int k = 0; k < arr.size(); k++) {
            for (int l = 0; l < arr[k].size(); l++) {
              sudahDikunjungi[k][l] = false;
            }	
          }			
  
          if (terbesar < (T * (T - 1))) {
            terbesar = (T * (T - 1)) ; 
            xBesar = i;
            yBesar = j;
          }
  
          T = 0;
        }
        
	   }

	}
    
    T = 0;
    klik2(xBesar, yBesar, arr[xBesar][yBesar]);
    sort(titikRuntuh.begin(), titikRuntuh.end());

    runtuhkan();
    cetak();
}

int main(){
    cin >> M >> N;
    
    arr.resize(M);
    sudahDikunjungi.resize(M);

    for(auto &row : arr) {
      row.resize(N);

    }

    for(auto &row : sudahDikunjungi) {
      row.resize(N);
    }

    
    for (int i = 0; i < M; i++) {
      for (int j = 0; j< N; j++) {
        int V;
        cin >> V;
        arr[i][j] = V;
      }
    }
    salinan = arr;

    solution();

}
