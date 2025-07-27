// Brute -  two array pos[] and neg[] of size n/2. iterate entire array and put accordingly, then put all pos[] on even index and neg[] on odd index
/*
    for(int i=0 to n){
    if(pos) pos[i] = arr[i];
    else neg[i] = arr[i];
    }
    for(int i=0; i<n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
    T.C. -> O(2n)     S.C. -> (n)
*/

// OPTIMAL

#include<iostream>
#include<vector>
using namespace std;

vector<int> Print(int *arr, int n){
    vector<int> res(n);
    int pos = 0;
    int neg = 1;
    for(int i=0; i<n; i++){
        if(arr[i] < 0){
            res[neg] = arr[i];
            neg+=2;
        }
        else{
            res[pos] = arr[i];
            pos+=2;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> newArr;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    newArr = Print(arr, n);
    for(int i=0; i<n; i++){
        cout << newArr[i]<< " ";
    }
    cout << endl;
}