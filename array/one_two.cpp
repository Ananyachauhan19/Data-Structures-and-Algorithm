#include<iostream>
#include<map>
using namespace std;

int find(int *arr, int n){
    
    // map<int, int> freq;

    // for(int i=0; i<n; i++){
    //     freq[arr[i]]++;
    // }

    // for(int i=0; i<n; i++){
    //     if(freq[arr[i]] == 1){
    //         return arr[i];
    //     }
    // }


    int Xor = 0;
    for(int i=0; i<n; i++){
        Xor ^= arr[i];
    }
    return Xor;
}


int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int res = find(arr, n);
    cout << res;

return 0;
}