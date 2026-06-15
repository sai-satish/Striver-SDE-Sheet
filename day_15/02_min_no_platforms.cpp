#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPlatforms(int n, int arr[], int dep[]) {
        vector<pair<int, int>> times;
        for (int i = 0; i < n; i++) {
            times.push_back({arr[i], 1});
            times.push_back({dep[i], -1});
        }
        sort(times.begin(), times.end());

        int platforms = 0, maxPlatforms = 0;
        for (const auto& time : times) {
            platforms += time.second;
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }        
};

int main() {
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    cout << "Minimum number of Platforms required " 
         << obj.countPlatforms(n, arr, dep) << endl;

    return 0;
}
