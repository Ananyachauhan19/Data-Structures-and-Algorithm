#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int>&dp){
    if(n<=1) return dp[n] = n;
    if(dp[n] != -1) return dp[n];

    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);

    for (int i = 0; i <= n; ++i) {
        fib(i, dp);
        cout << dp[i] << " ";
    }

}