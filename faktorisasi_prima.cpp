#include <iostream>
#include <cmath>
#include <map>


using namespace std;


bool isPrime(int x) {

 for(int i = 2; i <= sqrt(x) ; i++) {
 	if(x % i == 0) return false; 
 
 }
 return true;
}


void solution(long long N) {
	long long number = N;
	map<int, int> faktorisasiPrima;
	int i = 2;
	while(number > 1) {
		if(isPrime(i) && number % i == 0) {
			if(faktorisasiPrima.count(i) > 0) {
				faktorisasiPrima[i]++;
			} else {
				faktorisasiPrima[i] = 1;
			}
			number = number / i;
		} else {
			i++;
		}

	}
	
	for(auto it = faktorisasiPrima.begin() ; it != faktorisasiPrima.end() ; ++it) {

		if(it->second == 1) {
			cout << it->first << " ";
		
		} else {
			cout << it->first << "^" << it->second << " ";
		}

		if(next(it) != faktorisasiPrima.end()) {
			cout << "x ";
		}
	}

}

int main() {
	long long N;

	cin >> N;

	solution(N);



}
