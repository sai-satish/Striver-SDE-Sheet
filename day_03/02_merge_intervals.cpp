#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort the intervals based on the starting time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;

        //merging intervals
        for (const auto& interval : intervals) {
            if (mergedIntervals.empty() || mergedIntervals.back()[1] < interval[0]) {
                mergedIntervals.push_back(interval);
            } else {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            }
        }
        return mergedIntervals;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> mergedIntervals = sol.merge(intervals);
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}