#include <iostream>
#include <vector>

using namespace std;

vector<string>nama;
int N;

void solution () {
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (nama[j].size() > nama[j+1].size() || (nama[j].size() == nama[j+1].size() && nama[j] > nama[j+1] )) {
        string temp = nama[j];
        nama[j] = nama[j+1];
        nama[j+1] = temp;
      }
    }
  }


  for (int i = 0; i < N; i++) {
    cout << nama[i] << endl;
  }
}


int main (int argc, char *argv[]) {

  cin >> N;
  for (long long  i = 0; i < N; i++) {
    string A;
    cin >> A;
    nama.push_back(A);
  }
  
  solution();

  return 0;
}
