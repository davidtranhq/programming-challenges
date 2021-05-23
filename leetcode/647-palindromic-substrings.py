class Solution:
    """
    Time complexity: O(n^2)
    Space complexity: O(1)
    """
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

    """
    Uses Manacher's algorithm.

    Time complexity: O(n)
    Space complexity: O(n)
    """
    def countSubstrings2(self, s: str) -> int:
        def extendPalindrome(s: str, left: int, right: int) -> int:
            length = 0
            while (left >= 0 and right < len(s) and s[left] == s[right]):
                left -= 1
                right += 1
                length += 1
            return length
        # insert '#' between each letter (including leading and trailing) to turn even-lengthed
        # strings into odd lengths (so that palindromes always have a center)
        ss = "#" + "#".join(s) + "#"
        palindromeRadii = []
        left = 0 # index for the left boundary of the longest palindrome found so far
        right = -1 # right boundary
        length = len(ss)
        for center in range(length):
            radius = 0
            if center >= right:
                # current center is not inside the longest palindrome, so the length needs to be
                # calculated starting from 0
                radius = extendPalindrome(ss, center - 1, center + 1)
            else:
                # since current center IS inside the (longest) palindrome, the length is at least
                # as long as the length corresponding to the same letter on the other side of the palindrome
                # (or until the right boundary is reached)
                mirror = left + (right - center)
                minRadius = min(palindromeRadii[mirror], right - center + 1)
                radius = minRadius + extendPalindrome(ss, center - minRadius, center + minRadius) - 1
            palindromeRadii.append((radius + 1) // 2)
            if (center + radius > right):
                right = center + radius
                left = center - radius
        # don't include leading/trailing #
        return sum(palindromeRadii[1:-1])

a = Solution().countSubstrings2("abc")
print(a)
        