#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> rows, cols;
        vector<int> rows_zero_indexes = vector<int>(matrix.size(), 0);
        vector<int> cols_zero_indexes = vector<int>(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows_zero_indexes[i] = 1;
                    cols_zero_indexes[j] = 1;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (rows_zero_indexes[i] == 1 || cols_zero_indexes[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    sol.setZeroes(matrix);
    for (auto &row : matrix)
    {
        for (auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}