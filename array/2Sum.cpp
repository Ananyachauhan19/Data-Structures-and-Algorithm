#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

// BETTER
/* bool is(int *arr, int n, int target){
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        int a = arr[i];
        int b = target - a;
        if(mpp.find(b) != mpp.end()){
            return true;
        }
        mpp[a] = i;
    }
    return false;
}

pair<int, int> ind(int *arr, int n, int target){
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        int a = arr[i];
        int b = target - a;
        if(mpp.find(b) != mpp.end()){
            return {mpp[b], i};
        }
        mpp[a] = i;
    }
    return {-1 ,-1};
} */

bool optimal(vector<int> &arr, int n, int target){
    int i=0, j=n-1;
    sort(arr.begin(), arr.end());

    while(i < j){
        int sum = arr[i] + arr[j];
        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){
    int n, target;
    cin >> n >> target;
    // int arr[n];
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    /* bool res=is(arr, n, target);
    cout << res << endl;

    pair<int,int> indices = ind(arr, n, target);
    if(indices.first != -1){
        cout << "Indices: " << indices.first << " "<< indices.second << endl;
    }
    else{
        cout << "No valid pair found" << endl;
    } */

    bool res = optimal(arr, n, target);
    cout << res << endl;

return 0;
}