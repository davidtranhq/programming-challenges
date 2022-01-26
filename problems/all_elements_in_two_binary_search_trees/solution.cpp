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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        priority_queue<int, vector<int>, greater<int>> q;
        traverse(root1, q);
        traverse(root2, q);
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
    
    void traverse(TreeNode *root, priority_queue<int, vector<int>, greater<int>> &q) {
        if (!root)
            return;
        traverse(root->left, q);
        q.push(root->val);
        traverse(root->right, q);
    }
};