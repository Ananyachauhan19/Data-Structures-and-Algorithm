#include<iostream>
#include<vector>
using namespace std;

int jump(int i, int n, vector<int> &dp){
    if(i>n) return 0;
    if(i==n) return 1;
    if(dp[i] != -1)  return dp[i];
    return dp[n] = jump(i+1, n, dp) + jump(i+2, n, dp) + jump(i+3, n, dp);
}

int main(){
    int n;
    cin>>n;

    vector<int>dp(n+1, -1);
    int count = jump(0, n, dp);
    cout<< count;
}