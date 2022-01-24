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

reverse-order traversal (right-left-root), keeping track of a running sum of the nodes visited

int traverse(root, total)
    if (!root)
        return total;
    int new_total = traverse(root->right, total)
    root->val += new_total;
    new_total = traverse(root->left, root->val)
    return new_total;
    
    

*/
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root, 0);
        return root;
    }
    
    int traverse(TreeNode *root, int total) {
        if (!root)
            return total;
        int new_total = traverse(root->right, total);
        root->val += new_total;
        new_total = traverse(root->left, root->val);
        return new_total;
    }
};