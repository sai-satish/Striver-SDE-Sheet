#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    double power(double x, int n){
        if (n == 0) return 1.0;
        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
public:
    double myPow(double x, int n) {
        long N = n; // To handle the case when n is INT_MIN
        if( N < 0 ){
            return 1.0 / power(x, -1 *N);
        }
        return power(x, N);
    }
};

int main() {
    Solution sol;
    double x = 1.00000;
    int n = -2147483648;
    cout << sol.myPow(x, n) << endl;
    return 0;
}