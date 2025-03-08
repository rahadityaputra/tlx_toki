#include <iostream>

using namespace std;

const int mod =1000000007;


long long com[1001][1001];


void persiapan() {
for(int i = 0; i <= 1000; i++) {
        com[i][0] = com[i][i] = 1;
        for(int j = 1; j < i; j++) {
                com[i][j] = (com[i - 1][j] + com[i - 1][j - 1]) % mod;
        }
}

}





void solution(int N, int A, int B) {

        long long result = 0;

        for(int i = A; i <= B ; i++) {
                        result =  (result + com[N][i]) % mod;
        }


        cout << result << endl;;
}


// kemudian a mod 1000 000 007 ditambah b mod 1000 000 007 kemudian mod 1000 000 007

int main() {
        int N, A, B;
        persiapan();

cin >> N >> A >> B;
solution(N, A, B);



}
