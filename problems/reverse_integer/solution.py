class Solution:
    def reverse(self, x: int) -> int:
        if x < 10 and x > -1:
            return x
        k = -1 if x < 0 else 1
        rev = int(str(abs(x))[::-1].lstrip('0'))*k
        return rev if abs(rev) <= 2147483647 else 0