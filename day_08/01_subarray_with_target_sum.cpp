#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n)
{
    unordered_map<int, int> mpp;

    int maximum_length = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];

        if (sum == 0)
        {
            maximum_length = i + 1;
        }

        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maximum_length = max(maximum_length, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maximum_length;
}

int main()
{
    int A[] = {9, -3, 3, -1, 6, -5};
    int n = sizeof(A) / sizeof(A[0]);
    cout << maxLen(A, n) << endl;
    return 0;
}
