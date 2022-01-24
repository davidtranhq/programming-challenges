def longestSub(s, l, r):
    while l >=0 and r < len(s) and s[l] == s[r]:
        l -= 1
        r += 1
    return s[l+1:r]

class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest = ''
        for i in range(len(s)):
            even = longestSub(s, i, i)
            odd = longestSub(s, i, i+1)
            longest = max(even, odd, longest, key=len)
        return longest