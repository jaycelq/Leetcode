#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;

        while (n != 0)
        {
            n = n & n - 1;
            count++;
        }

        return count;
    }
};

int main()
{
    Solution s;
    cout << s.countDigitOne(5) << endl;
    return 0;
}
