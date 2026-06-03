#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (currentSum < 0) {
                currentSum = nums[i];
            } else {
                currentSum += nums[i];
            }
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums) << endl; // Output: 6
    return 0;
}