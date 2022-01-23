class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(nums1.begin(), nums1.end());
        int n = nums1.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            auto it = *s.rbegin() > nums2[i] ? s.upper_bound(nums2[i]) : s.begin();
            ans[i] = *it;
            s.erase(it);
        }
        return ans;
    }
};