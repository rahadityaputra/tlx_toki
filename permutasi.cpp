#include  <iostream>
#include  <vector>
using namespace std;
vector<int>hasil;
vector<bool>dipakai;
int N;

void solution(int kedalaman) {
 if (kedalaman > N) {
    for (int i = 0; i < N; i++) {
     cout << hasil[i] << " ";
    }
    cout << endl;
  } else  {
    for (int i = 1; i <= N; i++) {
      if(!dipakai[i]) {
	      dipakai[i] = true;
	      hasil.push_back(i);
	      solution(kedalaman + 1);

	      hasil.pop_back();
	      dipakai[i] = false;
      }

    }
  } 
}

int main (int argc, char *argv[]) {
  cin >> N;
  hasil.reserve(N);
  dipakai.assign(N+1, false);
  solution(1);

       
}
