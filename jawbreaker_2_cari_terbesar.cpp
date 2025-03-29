#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> sudahDikunjungi;
int M, N, B, K;

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

void solution() {
	int terbesar = 0;
	for (int i = 0; i < arr.size(); i++) {
	   for (int j = 0; j < arr[i].size(); j++) {
	   	klik(i, j, arr[i][j]);
                for (int k = 0; k < arr.size(); k++) {
                	for (int l = 0; l < arr[k].size(); l++) {
                		sudahDikunjungi[k][l] = false;
                	}	
                }			
		if (terbesar < (T * (T - 1))) {
			terbesar = (T * (T - 1)) ;
		}

		T = 0;
	   }
	}


	cout << terbesar << endl;
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

    solution();

}
