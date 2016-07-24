#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        else if (n == -1)
            return 1/x;
        else
        {
            double half = 0;
            half = myPow(x, n/2);
            if (n % 2 == 0)
                return half * half;
            else if (n > 0)
                return half * half * x;
            else
                return half * half / x;
        }
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2, -2147483648) << endl;
    return 0;
}
