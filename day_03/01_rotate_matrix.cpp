#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Transpose the matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //Reverse each row
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7}, {15,14,12,16}};
    sol.rotate(matrix);
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}