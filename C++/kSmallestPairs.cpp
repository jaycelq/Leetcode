#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct Pair
    {
        int first;
        int second;

        Pair (int first, int second)
        {
            this->first = first;
            this->second = second;
        }

        bool operator<(const Pair &other) const
        {
            return first + second < other.first + other.second;
        }
    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        priority_queue<Pair> pq;
        vector<pair<int, int>> result;

        for (int i = 0; i < min(k, (int)nums1.size()); i++)
        {
            for(int j = 0; j < min(k, (int)nums2.size()); j++)
            {
                if (pq.size() < k)
                    pq.push(Pair(nums1[i], nums2[j]));
                else
                {
                    Pair p = pq.top();
                    if(p.first + p.second > nums1[i] + nums2[j])
                    {
                        pq.pop();
                        pq.push(Pair(nums1[i], nums2[j]));
                    }
                }
            }
        }

        while(pq.empty() == false)
        {
            Pair p = pq.top();
            pq.pop();
            result.push_back(make_pair(p.first, p.second));
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
