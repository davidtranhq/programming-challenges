class Solution {
public:
    /*
    a + b: 4 possibilities
    even + even = even (add b)
    even + odd  = odd (subtract a)
    odd + even  = odd (no change)
    odd + odd   = even (add a + b)
    
    initialize vector of sums to length of queries + 1
    sums[0] = sum of even numbers in nums
    for i to length of queries
        query = queries[i]
        val = query[0]
        index = query[1]
        num = nums[index]
        diff = 0
        if (num odd and val odd):
            diff = -odd
        else if (num odd and val even):
            diff = val
        else if (num even and val odd):
            diff = num + val
        nums[index] += val
        sums[i + 1] = sums[i] + diff
        
    Time: O(n + q)
    Space: O(q)
    */
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n_queries = queries.size();
        vector<int> sums(n_queries);
        int first_sum = 0;
        for (int num : nums) 
        {
            if (num % 2 == 0)
                first_sum += num;
        }
        for (int i = 0; i < n_queries; ++i)
        {
            vector<int> query = queries[i];
            int val = query[0];
            int index = query[1];
            int num = nums[index];
            int diff = 0;
            bool num_even = num % 2 == 0;
            bool val_even = val % 2 == 0;
            if (num_even && val_even)
                diff = val;
            else if (num_even && !val_even)
                diff = -num;
            else if (!num_even&& !val_even)
                diff = num + val;
            nums[index] += val;
            sums[i] = (i == 0 ? first_sum : sums[i - 1]) + diff;
        }
        return sums;
    }
};