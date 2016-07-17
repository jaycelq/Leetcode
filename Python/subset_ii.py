class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if (len(nums) == 0 or len(nums) == 1):
            return nums
        else:
