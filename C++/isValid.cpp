#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        map<char, char> pair_map;
        
        pair_map[')'] = '(';
        pair_map[']'] = '[';
        pair_map['}'] = '{';
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            char pair;
            switch(c)
            {
            case '(':
            case '[':
            case '{':
                stack.emplace(c);
                break;
            case ')':
            case ']':
            case '}':
                if (stack.empty())
                    return false;
                pair = stack.top();
                stack.pop();
                if (pair != pair_map[c])
                {
                    return false;
                }
                break;
            default:
                return false;
            }
        }

        return stack.empty();
    }
};
