#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find entrance to the cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = sol.findDuplicate(nums);
    int sum = 0;
    for (auto num : nums) {
        sum += num;
    }
    int n = nums.size();
    int expected_sum = n * (n + 1) / 2;
    int missing = expected_sum - sum + duplicate;
    cout << "Duplicate: " << duplicate << ", Missing: " << missing << endl;
    return 0;
}