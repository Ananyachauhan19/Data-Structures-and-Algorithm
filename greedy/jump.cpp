#include <iostream>
#include<climits>
using namespace std;

int jump(int *arr, int n, int ind, int count){
    int mini = INT_MAX;
    if(ind >= n-1){
        return count;
    }
    for(int i=1; i <= arr[ind] ; i++){
        mini = min(mini, jump(arr, n, ind+i, count+1));
    }
    return mini;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int result = jump(arr, n, 0, 0);
    cout << result;
    return 0;
}