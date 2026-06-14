#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;
        for (int num : nums) {
            if (num == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            } else {
                currentCount = 0;
            }
        }
        return maxCount;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,0,1,1,1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl; // Output: 3
    return 0;
}