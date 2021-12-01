from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indices = {}
        for i, x in enumerate(nums):
            if target - x in indices:
                return [indices[target - x], i]
            indices[x] = i
    """
    Naive brute force: O(n^2) time
    """
    def twoSumSlow(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for i in range(length):
            for j in range(i + 1, length):
                if nums[i] + nums[j] == target:
                    return [i, j]

a = Solution().twoSum([3,2,4], 6)
print(a)