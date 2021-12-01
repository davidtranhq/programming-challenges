class Solution:
    def getSum(self, a: int, b: int) -> int:
        a = a if a > 0 else a & 1023
        b = b if b > 0 else b & 1023
        while b != 0:
            carry = a & b
            a = (a ^ b) & 0xfff
            b = (carry) << 1
        return a & 1023

a = Solution().getSum(1, -1)
print(a)