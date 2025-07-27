#include <iostream>
#include <vector>
using namespace std;

int inc(vector<int>& arr, int ind, int prev, vector<vector<int>>& dp){
    if(ind == arr.size()) return 0;
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

    int len = 0 + inc(arr, ind+1, prev, dp);
    if(prev == -1 || arr[ind] > arr[prev]){
        len = max(len, 1 + inc(arr, ind+1, ind, dp));
    }

    return dp[ind][prev+1] = len;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout << inc(arr, 0, -1, dp);
}