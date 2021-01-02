class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows >= len(s) or numRows == 1:
            return s
        rows = [''] * numRows
        row = 0
        step = 1
        for ch in s:
            rows[row] += ch
            if row == 0:
                step = 1
            elif row == numRows - 1:
                step = -1
            row += step
        return ''.join(rows)