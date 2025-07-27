#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void coins(vector<int> &coin, int X){
    vector<int> result;
    sort(coin.rbegin(), coin.rend());
    for(int i=0; i<coin.size(); i++){
        while(X >= coin[i]){
            X -= coin[i];
            result.push_back(coin[i]);
        }
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}

int main(){
    int n, X;
    cin >> n >> X;
    vector<int> coin(n);
     
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    coins(coin, X);
}