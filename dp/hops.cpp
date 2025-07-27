#include<iostream>
#include<vector>
using namespace std;

int ways(vector<int>&arr, int i, int n, vector<int>&dp){
    if(i >= n) return 0;
    
    if(dp[i] != -1) return dp[i];

    int oneStep = ways(arr, i+1, n, dp);
    int twoStep = ways(arr, i+2, n, dp);

    return dp[i] = arr[i] + min(oneStep, twoStep);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n+1, -1);

    int cost = min(ways(arr, 0, n, dp), ways(arr, 1, n, dp));
    cout << cost;
}