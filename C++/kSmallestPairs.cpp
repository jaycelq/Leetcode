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

class Solution2 {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<pair<int, int>> result;

        if (nums1.empty() || nums2.empty() || k <= 0)
        {
            return result;
        }

        auto comp = [&nums1, &nums2](pair<int, int> lhs, pair<int, int> rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);

        min_heap.emplace(0, 0);

        while (min_heap.empty() == false && k > 0)
        {
            auto idx_pair = min_heap.top();
            min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);

            if (idx_pair.first + 1 < nums1.size())
            {
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            }
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
            {
                min_heap.emplace(idx_pair.first, idx_pair.second+1);
            }
            k--;
        }

        return result;
    }
};

int main()
{

}

