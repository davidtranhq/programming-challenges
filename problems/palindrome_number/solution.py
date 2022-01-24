class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        digits = []
        while x >= 1:
            digits.append(x % 10)
            x = x // 10
        i, j = 0, len(digits)-1
        while i < j:
            if digits[i] != digits[j]:
                return False
            i += 1
            j -= 1
        return True