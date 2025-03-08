
#include <iostream>
#include <cmath>

using namespace std;


void adalahAgakPrima(long long N) {
	if(N == 1 || N == 2 || N == 3 || N == 5) {
		cout << "YA" << endl;
		return;
	}
	
	int count = 0;
	for(int i = 1 ; i <= sqrt(N) ; i++) {
		if(N % i == 0) {
			count++;
		}
	
		if(count > 2) {
			cout << "TIDAK" << endl;
			return;
		}
	}


	cout << "YA" << endl;
	return;



}

int main(){
	int T;
	cin >> T;

	int angka[T];

	for(int i = 0; i < T ; i++) {
		long long N;
		cin >> N;
		angka[i] = N;
	}


	for(int i = 0; i < T ; i++) {
		adalahAgakPrima(angka[i]);
	}
	

}
