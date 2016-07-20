#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int row, vector<bool>& mark, vector<bool>& c1, vector<bool> c2, int &num)
    {
        if (row == mark.size())
        {
            num++;
            return;
        }
        for(int col = 0; col < mark.size(); col++)
        {
            if(mark[col] == true || c1[row + col] == true || c2[row - col + mark.size() - 1] == true)
                continue;
            else
            {
                mark[col] = true;
                c1[row + col] = true;
                c2[row - col + mark.size() - 1] = true;
                dfs(row+1, mark, c1, c2, num);
                mark[col] = false;
                c1[row + col] = false;
                c2[row - col + mark.size() - 1] = false;
            }
        }
    }
    int totalNQueens(int n) {
        int num = 0;
        if (n <= 0)
            return num;
        vector<bool> mark(n, false);
        vector<bool> c1(2*n-1, false);
        vector<bool> c2(2*n-1, false);
        dfs(0, mark, c1, c2, num);
        return num;
    }
};

int main()
{
    Solution s;
    cout << s.totalNQueens(4) << endl;
    return 0;
}
