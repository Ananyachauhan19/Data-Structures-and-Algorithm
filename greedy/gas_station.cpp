#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gas_count(vector<int>&gas, vector<int>&cost){
    int start = 0;
    int t_cost = 0;
    int t_gas = 0;
    int tank = 0;
    for(int i=0; i<gas.size(); i++){
        t_gas += gas[i];
        t_cost += cost[i];
        tank = gas[i] - cost[i];
        while(tank < 0){
            start = i+1;
            tank = 0;
        }
    }
    return t_gas > t_cost ? start : -1;
   
}

int main(){
    int n;
    cin >> n;

    vector<int> gas(n);
    vector<int> cost(n);

    for(int i=0; i<n; i++){
        cin >> gas[i];
    }

    for(int i=0; i<n; i++){
        cin >> cost[i];
    }

    int str = gas_count(gas, cost);

    cout << "Starting index : " << str << endl;
}