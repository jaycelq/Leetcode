#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int length(unsigned int u)
    {
        if (u < 10)
            return 1;
        else if (u < 100)
            return 2;
        else
            return 3;
    }
    void helper(int index, const string &s, vector<string> &ans, vector<string> &result)
    {
        if (ans.size() == 4 && index == s.size())
        {
            string answer;
            for (int i = 0; i < ans.size() - 1; i++)
            {
                answer.append(ans[i] + ".");
            }
            answer.append(ans[ans.size() - 1]);
            result.emplace_back(answer);
            return;
        }
        else if (ans.size() >= 4 || index >= s.size())
        {
            return;
        }
        else
        {
            for (int i = index + 1; i <= s.size(); i++)
            {
                string p = s.substr(index, i - index);
                if(stoi(p) > 255 || p.length() != length(stoi(p)))
                    break;
                ans.emplace_back(p);
                helper(i, s, ans, result);
                ans.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        vector<string> ans;
        helper(0, s, ans, result);
        return result;
    }
};

int main()
{
    vector<string> result;
    Solution s;
    result = s.restoreIpAddresses("010010");
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
