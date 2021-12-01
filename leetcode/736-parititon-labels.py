class Solution:
    def partitionLabels(self, s: str) -> int:
        last = {c: i for i, c in enumerate(s)}
        start = end = 0
        ans = []
        for i, c in enumerate(s):
            end = max(end, last[c])
            if i == end:
                ans.append(end - start + 1)
                start = i + 1
        return ans