#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(nums, current, 0, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& current, int start, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);
            backtrack(nums, current, i + 1, result);
            current.pop_back();
        }
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Subsets with duplicates removed:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}