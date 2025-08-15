#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int is(vector<int> &arr, int n){
    int longest=1, cnt=0, last_min = INT_MIN;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(arr[i]-1 == last_min){
            cnt++;
            last_min = arr[i];
        }
        else if(arr[i] != last_min){
            cnt = 1;
            last_min = arr[i];
        }
        longest = max(longest, cnt);
    }

    return longest;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int res = is(arr, n);
    cout << res;
    return 0;
}
