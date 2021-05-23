from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        days = len(temperatures)
        stack = []
        untilWarm = [0] * days
        for i in range(days-1):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                j = stack.pop()
                untilWarm[j] = i - j
            stack.append(i)
        return untilWarm


