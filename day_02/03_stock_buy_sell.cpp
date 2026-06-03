#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceSoFar = prices[0];
        int maxProfit = 0;

        for (int price : prices) {
            minPriceSoFar = min(minPriceSoFar, price);
            maxProfit = max(maxProfit, price - minPriceSoFar);
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl; // Output: 5
    return 0;
}