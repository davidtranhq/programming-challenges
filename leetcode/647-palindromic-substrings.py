class Solution:
    def countSubstrings(self, s: str) -> int:
        def numPalindromes(s: str, left: int, right: int) -> int:
            pals = 0
            while (left >= 0 and right < len(s) and s[left] == s[right]):
                left -= 1
                right += 1
                pals += 1
            return pals
        pals = 0
        length = len(s)
        for i in range(length):
            pals += numPalindromes(s, i, i+1)
            pals += numPalindromes(s, i-1, i+1)
        return pals + length