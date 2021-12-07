/* scratch:

[1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0]

    
brute force:

i = j = 0
sums = 0
for i from 0 to n:
    for j from i to n:
        if sum of i to j == goal:
            sums += 1
            
Time: O(n^3)
Space: O(1)

-------------
prefix sums:

save a vectors sums[i] where sums[i] = sum from 0 to i (inclusive)

so to compute sum from a to b, compute sums[b] - sums[a - 1]

Time: O(n^2)
Space: O(n)

-------------
linear time:
- if nums[i] = 0, can add to sum and still be valid subarray
- since binary numbers, the goal = number of 1s in the subarray
- for any valid subarray (i, j), new subarrays can be created from suffixed 0's

potential solution:
- scan through once: note positions of 1's in vector places (a_0, a_1, a_2, a_3, a_4, a_5, a_e)
    - where a_0 points to one before the beginning (-1), a_e points to one past the end
- define a "longest subarray s" as the subarray between (exclusive) any two a_i, a_j in vector where j - i == goal + 1
    - inside longest subarray, there are (1 + number of trailing zeros) * (number of leading zeros + 1) valid subarrays
- to find longest subarrays:
    for i in 0 to e:
        j = i + goal + 1
        leading = places[i + 1] - places[i]
        trailing = places[j] - places[j - 1] - 1
        total += (trailing + 1) * (leading + 1)
    return total
    
case: goal = 0:
    longest subarrays are (a_i, a_{i + 1}) (zeroes in between ones)
    number of valid subarrays for a longest subarray of length k is k(k + 1) / 2
case: not enough ones: goal = 2 [0, 1, 0]
    
Time: O(n)
Space: O(n)

------------
better prefix sums (linear time):

for i from 0 to n:
    pre[i] = get ith prefix sum
    if (pre[i] == goal) total += 1
    total += number of sums with sum = pre[i] + S
    sums[pre[i]] += 1
    
Time: O(n)
Space: O(n)

-----------
linear time, constant space? :

*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pre(n);
        map<int, int> sums;
        int total = 0;
        for (int i = 0; i < n; ++i) {
            pre[i] = nums[i] + ((i == 0) ? 0 : pre[i - 1]);
            int p = pre[i];
            if (p == goal)
                ++total;
            total += sums[p - goal];
            ++sums[p];
        }
        return total;
    }
};