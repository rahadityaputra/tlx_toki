#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> sudahDikunjungi;
int M, N, B, K;




void solution() {
  
}

int T;
void klik(int x, int y, int warna){
  if (x < M && y < N && x >= 0 && y >= 0) {
    if (!sudahDikunjungi[x][y]) {
      if (arr[x][y] == warna) {
        T++;
        sudahDikunjungi[x][y] = true;
        klik(x+1, y, warna);
        klik(x-1, y, warna);
        klik(x, y+1, warna);
        klik(x, y-1, warna);
      } 
    }
  }
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

    cin >> B >> K;

    klik(B, K, arr[B][K]);
    cout << T * (T - 1) << endl;
}
