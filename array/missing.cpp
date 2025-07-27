#include<iostream>
using namespace std;

int find(int *arr, int n){
    int xor1 = 0, xor2 = 0;
    // for(int i=1; i<=n; i++){
    //     xor1 ^= i;
    // }
    for(int i=0; i<n-1; i++){
        xor2 ^= arr[i];
        xor1 ^= (i+1);
    }
    xor1 ^= n;

    return xor1 ^ xor2;
}

// int find(int *arr, int n){
//     int sum1=(n * (n + 1)) / 2, sum2=0;
//     for(int i=0; i<n-1; i++){
//         sum2 += arr[i];
//     }
//     return sum1-sum2;
// }

int main(){
    int n;
    cin >> n;
    int arr[n-1];

    for(int i=0; i<n-1; i++){
        cin >> arr[i];
    }

    int res = find(arr, n);
    cout << res;

return 0;
}