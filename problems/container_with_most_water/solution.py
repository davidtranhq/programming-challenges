class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        i = 0
        j = n - 1
        max_area = 0
        while i < j:
            left = height[i]
            right = height[j]
            area = min(left, right) * (j - i)
            max_area = max(area, max_area)
            if left <= right:
                i += 1
            else:
                j -= 1
        return max_area
            
        