#include <iostream>
using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int guess_result = guess(mid);
            if (guess_result == 0)
                return mid;
            else if (guess_result > 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low; 
    }
};
