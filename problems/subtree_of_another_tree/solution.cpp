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

void traverse(root, match):
    if (root->val == match->val)
        traverse(root->left, match->left)
        traverse(root->right, match->right)
        
void match(t1, t2):
    if (!t1 != !t2)
        return false
    else if (!t1 && !t2)
        return true
    if (t1->val != t2->val)
        return false
    return match(t1->left, t2->left) && match(t1->right, t2->right)

*/

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        if (root->val == subRoot->val && match(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool match(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2)
            return true;
        else if (!t1 != !t2 || t1->val != t2->val)
            return false;
        return match(t1->left, t2->left) && match(t1->right, t2->right);
    }
};