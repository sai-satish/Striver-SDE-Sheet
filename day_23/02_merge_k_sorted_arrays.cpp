#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
        vector<int> result;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        for (int i = 0; i < k; i++) {
            if (!arr[i].empty()) {
                minHeap.push({arr[i][0], {i, 0}});
            }
        }

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int value = top.first;
            int row = top.second.first;
            int col = top.second.second;

            result.push_back(value);

            if (col + 1 < arr[row].size()) {
                minHeap.push({arr[row][col + 1], {row, col + 1}});
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int k = arr.size();
    vector<int> result = sol.mergeKSortedArrays(arr, k);
    
    cout << "Merged sorted array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}