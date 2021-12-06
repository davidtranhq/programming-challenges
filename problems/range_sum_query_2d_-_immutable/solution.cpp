/* scratch:

O(mn) space, O(1) time

store 2d matrix where each entry (i,j) is the sum of entries from (i,j) to (m, n)
then, to compute any rectangle (r1, c1, r2, c2):
    add sums[r1][c1]
    subtract sums[r2 + 1][c1] (bottom rectangle)
    subtract sums[r1][c1 + 1] (right rectangle)
    add overlap of bottom/right rectangle: sums[r2 + 1][c2 + 1]
    
to populate sums: dp
    start with base case sums[m - 1][n - 1] = matrix[m - 1][n - 1]
    let a = m - i, b = n - j
    sums[a][b] = sums[a + 1][b] (bottom rectangle)
        + sums[a][b + 1] (right rectangle)
        - sums[a + 1][b + 1] (double counted overlap of the two)

*/
class NumMatrix {
private:
    vector<vector<int>> sums;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        sums.resize(m, vector<int>(n));
        sums[m - 1][n - 1] = mat[m - 1][n - 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int a = m - 1 - i;
                int b = n - 1 - j;
                bool last_row = a == m - 1;
                bool last_col = b == n - 1;
                int bottom_sum = last_row ? 0 : sums[a + 1][b];
                int right_sum = last_col ? 0 : sums[a][b + 1];
                int overlap = (last_row || last_col) ? 0 : sums[a + 1][b + 1];
                sums[a][b] = mat[a][b] + bottom_sum + right_sum - overlap;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        bool last_row = row2 == m - 1;
        bool last_col = col2 == n - 1;
        return sums[row1][col1]
            - (last_row ? 0 : sums[row2 + 1][col1])
            - (last_col ? 0 : sums[row1][col2 + 1])
            + (last_row || last_col ? 0 : sums[row2 + 1][col2 + 1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */