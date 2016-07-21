#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int row, vector<bool> &mark, vector<bool> &c1, vector<bool> &c2, vector<string> &ans, vector<vector<string>> &result)
    {
        int size = mark.size();
        if (row == size)
        {
            result.emplace_back(ans);
            return;
        }

        for (int col = 0; col < size; col++)
        {
            if (mark[col] == true || c1[row + col] == true
                || c2[row - col + size -1] == true)
                continue;
            else {
                string row_ans = col > 0 ? string(col, '.') : "";
                row_ans.push_back('Q');
                row_ans.append(size - 1 - col, '.');
                mark[col] = c1[row + col] = c2[row - col + size - 1] = true;
                mark[col] = c1[row + col] = c2[row - col + size - 1] = true;
                ans.emplace_back(row_ans);
                dfs(row + 1, mark, c1, c2, ans, result);
                ans.pop_back();
                mark[col] = c1[row + col] = c2[row - col + size - 1] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> ans;
        vector<bool> mark(n, false);
        vector<bool> c1(2*n - 1, false);
        vector<bool> c2(2*n - 1, false);
        dfs(0, mark, c1, c2, ans, result);
        return result;
    }
};

int main()
{
    vector<vector<string>> result;
    Solution s;
    result = s.solveNQueens(4);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << endl;
        }
    }

    return 0;
}
