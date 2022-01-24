class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indices = {}
        for i, x in enumerate(nums):
            if target - x in indices:
                return [indices[target - x], i]
            indices[x] = i