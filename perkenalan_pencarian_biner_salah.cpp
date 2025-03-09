#include <iostream>
#include <vector>

using namespace std;

unsigned int N, Q;
vector<unsigned int>A;
vector<vector<unsigned int>>pertanyaan(100000, vector<unsigned int>(2));


int mundur(unsigned int x, unsigned int y, unsigned int start) {
  unsigned int count = 0;
  while (y >= A[start] && x < A[start] ) {
    count++;
    if (start == 0) {
      break;
    }
    start = start - 1;
  }
  return count;
}
int maju(unsigned int x, unsigned int y, unsigned int start) {
  unsigned int count = 0;
  while (y >= A[start] && x < A[start] ) {
    count++;
    start = start + 1;
  }
  return count;
}



int cari(unsigned int x, unsigned int y) {
  if (x >= A.back() || y < A[0]) {
    return 0;
  }

  unsigned int start = 0;
  unsigned int finish = A.size() - 1;
  unsigned int tengah;
  while (start <= finish) {
    tengah = ((finish + start)/ 2);
    if (A[tengah] >= y) {
      if (A[tengah] == y) {
        return mundur(x,y,tengah);
      } else {
        finish = tengah - 1;
      }
      
    } else if (A[tengah] <= x) {
      if (A[tengah] == x) {
        return maju(x, y, tengah + 1);
      } else {
        start = tengah + 1;
      }
    } else if (A[tengah] > x && A[tengah] <= y){
      return mundur(x, y, tengah) + maju(x, y, tengah + 1);
    } else {
      start = tengah + 1;
    }

  if (start == finish) {
    if (A[finish] > y) {
      return mundur(x, y, finish - 1); 
    }
  }

    
  }

  
  return 0;
}

void solution() {
  for (unsigned int i = 0; i < Q; i++) {
   cout << cari(pertanyaan[i][0], pertanyaan[i][1]) << endl;
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
    pertanyaan[i][0] = x;
    pertanyaan[i][1] = y;
 }


 solution();


}
