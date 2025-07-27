// Brute - sort 
// Better - iterate over array and sount for each 0 , 1, 2 and then again run a loop and manual overwrite for 0 then 1 then 2
// Optimal - low, mid, high

#include<iostream>
using namespace std;

void sorted(int *arr, int n){
    int mid = 0;
    int high = n-1;
    int low = mid;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sorted(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}