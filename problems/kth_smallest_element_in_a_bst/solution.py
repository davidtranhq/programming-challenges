# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def traverse(node: TreeNode) -> List[int]:
            return traverse(node.left) + [node.val] + traverse(node.right) if node else []
        return traverse(root)[k-1]
        
        