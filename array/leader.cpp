#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> is(vector<int> &arr, int n){
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i = n-1; i>=0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> res = is(arr, n);
    for(auto it : res){
        cout << it << " ";
    }
    return 0;
}
