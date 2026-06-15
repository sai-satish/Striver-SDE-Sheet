#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, [](Item a, Item b) {
            double r1 = (double) a.value / (double) a.weight;
            double r2 = (double) b.value / (double) b.weight;
            return r1 > r2;
        });

        int curWeight = 0;
        double finalvalue = 0.0;
        for (int i = 0; i < n; i++) {
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            } else {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
                break;
            }
        }
        return finalvalue;
    }
};

int main() {
    int n = 3, weight = 50;  // Number of items and capacity of knapsack
    // Item values and weights
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;

    // Calculate the maximum value we can get with the fractional knapsack
    double ans = obj.fractionalKnapsack(weight, arr, n);
    
    // Output the result
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    
    return 0;
}