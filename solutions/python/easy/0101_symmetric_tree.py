class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def is_mirror(self, left, right):
        if not left or not right:
            return left == right
        return (left.val == right.val
                and self.is_mirror(left.left, right.right)
                and self.is_mirror(left.right, right.left))

    def isSymmetric(self, root: TreeNode) -> bool:
        return self.is_mirror(root.left, root.right)

