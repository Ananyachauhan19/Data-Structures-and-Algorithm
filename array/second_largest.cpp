#include<iostream>
using namespace std;

int secondLargest(int *arr, int n){
    int largest = 0, second = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > largest){
            second = largest;
            largest = arr[i];
        }
    }

    return second;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int res=secondLargest(arr, n);
    cout << res;

return 0;
}