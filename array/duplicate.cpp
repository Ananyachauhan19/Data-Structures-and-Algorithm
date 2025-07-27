#include<iostream>
using namespace std;

int dupli(int *arr, int n){
    int j = 0 ;
    for(int i=1; i<n; i++){
        if(arr[i] != arr[j]){
            j++;
            arr[j] = arr[i]; 
        }
    }
    return j+1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int newSize = dupli(arr, n);

    for(int i=0; i<newSize; i++){
        cout << arr[i] << " ";
    }

return 0;
}