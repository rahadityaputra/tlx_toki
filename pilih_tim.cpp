#include <iostream>
#include <vector>


using namespace std;


vector<vector<int>>dp;

const int MOD = 1000000007;
int combination(int n, int k) {
        
        

        if(k == 0 || n == k) return 1;
        if(dp[n][k] != -1) return dp[n][k];
        return dp[n][k] = (combination(n - 1, k) + combination(n - 1, k - 1)) % MOD; 
}

int main(){
    int N, K;
    cin >> N >> K;

    cout << combination(N, K) % MOD << endl;

}


