#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long merge(vector<int>& arr, int low, int mid, int high) {
        long long cnt = 0;

        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high &&
                (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            cnt += right - (mid + 1);
        }

        vector<int> temp;
        int left = low;
        right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    long long mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        long long cnt = 0;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return (int) mergeSort(nums, 0, nums.size() - 1);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,3,2,3,1};
    int result = sol.reversePairs(nums);
    cout << result << endl;
    return 0;
}