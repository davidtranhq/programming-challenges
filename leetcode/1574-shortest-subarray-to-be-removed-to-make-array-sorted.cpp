/* scratch:

[1, 2, 3, 10, 4, 2, 3, 5]

brute force:
[i, j]: subarray to remove
for each [i,j]:
    check if removing subarray makes non-decreasing
        update minimum
        
Time: O(n^3)
Space: O(1)

---------------------------
notice that final array will start at beginning, end at end, or both
[0, i]: sorted prefix subarray
[j, n]: sorted suffix subarray
while a[i] is increasing:
    increment i
while a[j] is decreasing:
    decrement j

now we have window [k, l] to slide, where k < i and l > m
while (k < i && l < n):
    if a[k] <= a[l]:
        save k - l + 1 as potential solution
        if (k < i)
    
    

*/

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &a)
    {
        int n = a.size();
        int i;
        for (i = 0; i < n - 1; ++i)
        {
            if (a[i] > a[i + 1])
            {
                break;
            }
        }
        if (i == n - 1)
        {
            return 0; // array is non-decreasing already
        }
        int j;
        for (j = n - 1; j > 0; --j)
        {
            if (a[j] < a[j - 1])
            {
                break;
            }
        }
        int ans = min(j, n - i - 1);
        int k = 0, l = j;
        while (k <= i && l < n)
        {
            if (a[k] <= a[l])
            {
                ans = min(ans, l - k - 1);
                ++k;
            }
            else
            {
                ++l;
            }
        }
        return ans;
    }
};