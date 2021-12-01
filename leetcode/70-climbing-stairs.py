class Solution:
    '''
    DP solution in O(n) time.
    Note the question is asking the same as finding the nth fibonacci number.
    '''
    def climbStairs(self, n: int) -> int:
        a = 1
        b = 1
        for _ in range(n):
            a, b = b, a + b
        return a