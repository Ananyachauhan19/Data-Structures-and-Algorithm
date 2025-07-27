// Brute - iterate and count each arr[i], if count > n/2 return arr[i]
// Better - hashing

#include<iostream>
#include<map>
using namespace std;

// BETTER

/* int major(int *arr, int n){
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
} */

// OPTIMAL

int major(int *arr, int n){
    int count = 0;
    int el;
    for(int i=0; i<n; i++){
        if(count == 0){
            count = 1;
            el = arr[i];
        }
        else if(arr[i] == el){
            count++;
        }
        else{
            count--;
        }
    }

    //Check if majority elements exists or not
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == el){
            cnt1++;
        }
    }

    if(cnt1 > n/2) return el;

    return -1;
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int res = major(arr, n);
    cout << res;
    cout << endl;
}