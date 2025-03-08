#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> A (999999, true);
vector<long long> B;


void prima() {
    A[0] = false;
    A[1] = false;

    for(long long i = 2; i <= sqrt(A.size()); i++) {
        if(A[i]) {
            B.push_back(i);
            for(long long j = i * i; j < A.size(); j += i) {
                A[j] = false;
            }
        }
    }

    for (long long i = sqrt(A.size()) + 1; i < A.size(); i++) {
        if (A[i]) {
            B.push_back(i);
        }
    }

}


int main() {
    long long T, K;
    cin >> T;
   vector<long long> number(T);
    prima();

    for(long long i = 0; i < T; i++) {
        cin >> K;
        number[i] = K;
    }




    for(long long i = 0; i < T; i++) {
	    cout << B[number[i] - 1] << endl;
    }

}
