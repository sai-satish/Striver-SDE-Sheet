#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(0);
        vector<int> row;
        for (int i = 0; i < numRows; i++)
        {
            row.push_back(1);
            for (int j = i - 1; j > 0; j--)
            {
                row[j] = row[j] + row[j - 1];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};

int main()
{
    Solution sol;
    int numRows = 5;
    vector<vector<int>> result = sol.generate(numRows);
    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}