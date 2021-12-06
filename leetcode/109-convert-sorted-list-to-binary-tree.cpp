/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

/* scratch: Time: O(n), Space: O(n)
    Space: O(log n)
    
    global head = head
    get length of list n
    return tree(0, n - 1)
    
    TreeNode *tree(lo, hi) {
        if (lo > hi)
            return nullptr;
        mid = (lo + hi) / 2
        left = tree(lo, mid - 1)
        val = value from head
        head = head->next
        right = tree(mid + 1, hi)
        return new TreeNode(val, left, right)
    }
*/

class Solution
{
private:
    ListNode *curr;

public:
    TreeNode *tree(int lo, int hi)
    {
        if (lo > hi)
            return nullptr;
        int mid = (lo + hi) / 2;
        TreeNode *left = tree(lo, mid - 1);
        int val = curr->val;
        curr = curr->next;
        TreeNode *right = tree(mid + 1, hi);
        return new TreeNode(val, left, right);
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        int n = 0;
        curr = head;
        while (curr)
        {
            ++n;
            curr = curr->next;
        }
        curr = head;
        return tree(0, n - 1);
    }
};

/* scratch: Time: O(n), Space: O(n)
    what order to put them in?
    let m(i, j) = list[(i + j) / 2]
    
    put the middle element of each partition in
    
    [0, 1, 2, 3, 4, 5, 6] => 3, 1, 0, 2, 5, 4, 6
    
    [0, 1, 2, 3, 4, 5] =>  2, 0, 1, 4, 3, 5
    
    but then we have to traverse the subtree everytime, lets try and work bottom up
    
    base cases:
        1 node: root
        2 nodes: left-root
        3 nodes: left-root-right
        
    convert linked list into vector
    m = n / 2
    left = n / 4
    right - n / 2 + n / 4
    root = node(tree(left), tree(right))
    
    def tree(lo, hi):
        mid = (lo + hi) / 2;
        value = values[mid]
        return new TreeNode(mid, tree(lo, mid - 1), tree(mid + 1, hi)
        
    [0, 1, 2, 3, 4, 5, 6]
        => tree(0, 6)
            => tree(0, 2)
                => tree(0, 0)
                => tree(2, 2)
            => tree(4, 6)
                => tree(4, 4)
                => tree(6, 6)
    [0, 1, 2, 3, 4, 5]
        => tree(0, 5)
            => tree(0, 1)
                => tree(0, 0)
                => tree(1, 1)
            => tree(3, 5)
            
            
    O(n) time
    O(n) space
    create values vector from linked list
    TreeNode *tree(values, lo, hi)
        if lo == hi:
            return TreeNode(values[lo])
        mid = (lo + hi) / 2
        left = tree(values, lo, max(mid - 1, lo))
        right = tree(values, min(mid + 1, hi), hi)
        return TreeNode(values[mid], left, right)

class Solution {
public:
    TreeNode *tree(const vector<int> &values, int lo, int hi) {
        if (lo >= hi)
            return new TreeNode(values[lo]);
        int mid = (lo + hi) / 2;
        TreeNode *left = tree(values, lo, mid - 1);
        TreeNode *right = tree(values, mid + 1, hi);
        TreeNode *root;
        if (mid == lo) {
            root = right;
            root->left = left;
        } else {
            root = new TreeNode(values[mid], left, right);
        }
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> values;
        ListNode *curr = head;
        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        int n = values.size();
        if (n == 0)
            return nullptr;
        return tree(values, 0, values.size() - 1);
    }
};
*/