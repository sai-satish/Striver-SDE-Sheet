#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int majority_num = nums[0];
        int count = 1;

        for (int i = 1; i < size; i++) {
            if (nums[i] == majority_num) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    majority_num = nums[i];
                    count = 1;
                }
            }
        }

        return majority_num;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << sol.majorityElement(nums) << endl; // Output: 2
    return 0;
}