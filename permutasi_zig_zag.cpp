#include  <iostream>
#include  <vector>
using namespace std;
vector<int>hasil;
vector<bool>dipakai;
int N;


bool cekBukitLembah() {
	int len = hasil.size();

	if (len < 3) 
	{
		return true;
	}

	int A = hasil[len -3];
	int B = hasil[len -2];
	int C = hasil[len -1];
	
	return (A > B && B < C) || (A < B && B > C); 
}



void solution(int kedalaman) {
 if (kedalaman > N) {
    for (int i = 0; i < N; i++) {
     cout << hasil[i];
    }
    cout << endl;
  } else  {
    for (int i = 1; i <= N; i++) {
      if(!dipakai[i]) {
	      

	      dipakai[i] = true;
	      hasil.push_back(i);

		  if (cekBukitLembah())
		  {
			solution(kedalaman + 1);
			
		  }
		  
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

