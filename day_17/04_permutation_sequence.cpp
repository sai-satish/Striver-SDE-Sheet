#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        string result;
        k--; // Convert k to 0-based index
        int factorial = 1;
        for (int i = 1; i < n; ++i) {
            factorial *= i;
        }

        for (int i = 0; i < n; ++i) {
            int index = k / factorial;
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            if (i < n - 1) {
                k %= factorial;
                factorial /= (n - 1 - i);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    int n = 3, k = 3;
    string result = sol.getPermutation(n, k);
    cout << "The " << k << "-th permutation of numbers from 1 to " << n << " is: " << result << endl;
    return 0;
}