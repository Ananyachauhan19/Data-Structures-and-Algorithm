#include<iostream>
using namespace std;

int is(int *arr, int n){
    int mini = arr[0];
    int minIndex = 0;
    int profit = 0;
    int buyDay = 0, sellDay = 0;

    for(int i=1; i<n; i++){
        int cost = arr[i] - mini;
        if(cost > profit){
            profit = cost;
            buyDay = minIndex;
            sellDay = i;
        }
        if(arr[i] < mini){
            mini = arr[i];
            minIndex = i;
        }
    }

    cout << "Best day to buy stock is Day " << buyDay 
         << " (Price = " << arr[buyDay] << ") and sell stock is Day " << sellDay 
         << " (Price = " << arr[sellDay] << ")" << endl;
    
    return profit;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int res = is(arr, n);
    cout << "Maximum Profit: " << res << endl;

    return 0;
}
