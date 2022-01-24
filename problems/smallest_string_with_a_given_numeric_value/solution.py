class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        s = 'a' * n
        # difference between goal value and value of string of a's
        diff = k - n
        # replace trailing a's with as many z's as possible
        zs = diff // 25
        if (zs == n):
            return 'z' * n
        if (zs == 0):
            # replace the last letter with whatever is needed to reach k
            s = s[:-1] + chr(ord('a')+diff)
            return s
        s = s[:-zs] + 'z' * zs
        # letter preceding the z's is replaced to meet the expected value
        leftover = diff - (zs * 25)
        s = s[:-zs-1] + chr(ord('a') + leftover) + s[-zs:]
        return s
