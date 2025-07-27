#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinimumPlatforms(vector<int> &arrival, vector<int> &departure) {
   int n = arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int plat_needed = 1, maxp = 1;
    int i = 1, j = 0;
    while(i<n && j<n){
        if(arrival[i] <= departure[j]){
            plat_needed++;
            i++;
        }
        else{
            plat_needed--;
            j++;
        }
        maxp = max(plat_needed, maxp);
    }
    return maxp;
}

int main() {
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    vector<int> arrival(n), departure(n);
    cout << "Enter arrival times:\n";
    for(int i = 0; i < n; ++i) {
        cin >> arrival[i];
    }

    cout << "Enter departure times:\n";
    for(int i = 0; i < n; ++i) {
        cin >> departure[i];
    }

    int result = findMinimumPlatforms(arrival, departure);
    cout << "Minimum number of platforms required: " << result << endl;

    return 0;
}
