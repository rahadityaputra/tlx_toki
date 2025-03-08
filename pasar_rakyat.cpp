#include <iostream>
#include <numeric>

using namespace std;

void solution(int N) {

for(int i = 1 ; i < N; i++) {
    kpk = (kpk * D[i]) / gcd(kpk, D[i]);
}
 cout << kpk << endl;
} 

int main(){

int N;
cin >> N;
for (int i = 0;  i < N; i++) {
    long long b ;
    cin >> b;
    D[i] = b;
}

solution(N);


}

