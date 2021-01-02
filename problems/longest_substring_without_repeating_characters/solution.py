class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        chars = {}
        longest = 0
        for j in range(len(s)):
            c = s[j]
            if c in chars and i < chars[c]:
                i = chars[c]
            length = j - i + 1
            if length > longest:
                longest = length
            chars[c] = j+1
        return longest
            