/* scratch

goal: divide jobDifficulty into d subarrays such that sum of max values in each subarray is minimal

intuition:
problem requires finding a specific permutation (order of slice indices to make).
searching a permutation tree with DFS is a good place to start.

consider the simplest case: d = 1.
then ans is max of A

now d > 1
define a slice k_y as the first job of day y, 0 <= y < d
    e.g. [6, 5, 4, 3, 2], if k_1 = 2, then the tasks are split as
    [6, 5], [4, 3, 2] (notice that k_0 is always 0)

notice: y <= s_y <= n - d since each day must have at least one job

if s_y = i, then ans is
    max of A from [0, i - 1] + minDifficulty for the rest of the array [i, n - 1]
                               ^
                               this is the recursive part

pseudocode:
int dfs(A, d, k):
    n = length of d
    if d == 1:
        return max of A from [k, n]
    else:
        ans = infinity
        for i = k to n - d:
            today = max of A from [k, i]
            ans = min(ans, today + minDifficulty(A, d - 1, i + 1))
            
Time: O(n * binom(n, d - 1))
Space: O(d)

TLE...



*/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d > n) 
            return -1;
        cache.resize(d, vector<int>(n, -1));
        return dfs(jobDifficulty, d, 0);
    }
    
    int dfs(const vector<int> &A, int d, int k) {
        int n = A.size();
        if (d == 1) {
            return *max_element(A.cbegin() + k, A.cend());
        } else {
            if (cache[d - 2][k] != -1) 
                return cache[d - 2][k];
            int ans = numeric_limits<int>::max();
            int max_today = A[k];
            for (int i = k + 1; i <= n - d + 1; ++i) {
                ans = min(ans, max_today + dfs(A, d - 1, i));
                max_today = max(max_today, A[i]);
            }
            cache[d - 2][k] = ans;
            return ans;
        }
    }
private:
    vector<vector<int>> cache;
};