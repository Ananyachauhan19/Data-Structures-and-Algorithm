#include<iostream>
using namespace std;

bool is(int *arr, int n){
    for(int i=0; i<n-1; i++){
        if(arr[i] <= arr[i+1]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bool res=is(arr, n);
    cout << res;

return 0;
}