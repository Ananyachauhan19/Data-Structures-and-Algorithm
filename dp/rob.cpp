#include<iostream>
#include<vector>
using namespace std;

int ways(vector<int>&arr, int n, vector<int>&dp){
    if(n<0) return 0;
    
    if(dp[n] != -1) return dp[n];

    return dp[n] = max(arr[n] + ways(arr, n-2, dp), ways(arr,n-1, dp));
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n, -1);

    int cost = ways(arr, n-1, dp);
    cout << cost;
}