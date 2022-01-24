/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans_ = 0;
    unordered_map<int, int> prefixes_;
    
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0);
        return ans_;
    }
    
    void dfs(TreeNode *root, int target, int prefix) {
        if (!root)
            return;
        int sum = root->val + prefix;
        if (sum == target)
            ++ans_;
        ans_ += prefixes_[sum - target];
        prefixes_[sum] += 1;
        dfs(root->left, target, sum);
        dfs(root->right, target, sum);
        prefixes_[sum] -= 1;
    }
};