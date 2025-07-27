#include<iostream>
#include<vector>
using namespace std;

int climb(int n, vector<int> &dp){
    if(n<=1) return 1;
    if(dp[n] != -1)  return dp[n];
    return dp[n] = climb(n-1, dp) + climb(n-2, dp);
}

int main(){
    int n;
    cin>>n;

    vector<int>dp(n+1, -1);
    int count = climb(n, dp);
    cout<< count;
}