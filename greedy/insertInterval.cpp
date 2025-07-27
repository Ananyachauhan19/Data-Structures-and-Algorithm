#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();

    // Step 1: Add intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge overlapping intervals with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);

    // Step 3: Add remaining intervals after merged newInterval
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

// Helper function to print intervals
void printIntervals(const vector<vector<int>>& intervals) {
    for (auto it : intervals) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n; // number of existing intervals

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> result = insertInterval(intervals, newInterval);

    printIntervals(result);

    return 0;
}
