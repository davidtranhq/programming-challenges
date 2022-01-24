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

/* scratch:
consider tree of n = 3 left-root-right


    


*/
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        coinsNeeded(root, ans);
        return ans;
    }
    
    int coinsNeeded(TreeNode *root, int &ans) {
        if (!root)
            return 0;
        int left = coinsNeeded(root->left, ans);
        int right = coinsNeeded(root->right, ans);
        ans += abs(left) + abs(right);
        return left + right - root->val + 1;
    }
};