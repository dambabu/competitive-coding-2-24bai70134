# Experiment 2.2.1
# Lowest Common Ancestor of a Binary Tree
# LeetCode Problem #236


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lowestCommonAncestor(self, root, p, q):

        # Base case
        if root is None or root == p or root == q:
            return root

        # Search in left and right subtrees
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        # If both sides return a node,
        # current root is the Lowest Common Ancestor
        if left is not None and right is not None:
            return root

        # Return the non-null result
        return left if left is not None else right


def build_tree(values):
    """Build a binary tree from level-order values."""

    if not values or values[0] == '#':
        return None

    nodes = [
        TreeNode(value) if value != '#' else None
        for value in values
    ]

    child_index = 1

    for node in nodes:
        if node is not None:

            if child_index < len(nodes):
                node.left = nodes[child_index]
                child_index += 1

            if child_index < len(nodes):
                node.right = nodes[child_index]
                child_index += 1

    return nodes[0]


def find_node(root, value):
    """Find a node by its value."""

    if root is None:
        return None

    if root.val == value:
        return root

    left_result = find_node(root.left, value)

    if left_result is not None:
        return left_result

    return find_node(root.right, value)


# Main program
if __name__ == "__main__":

    # Example tree:
    #
    #          3
    #        /   \
    #       5     1
    #      / \   / \
    #     6   2 0   8
    #        / \
    #       7   4

    values = [3, 5, 1, 6, 2, 0, 8, '#', '#', 7, 4]

    root = build_tree(values)

    p_value = 5
    q_value = 1

    p = find_node(root, p_value)
    q = find_node(root, q_value)

    solution = Solution()

    answer = solution.lowestCommonAncestor(root, p, q)

    print("Experiment 2.2.1: Lowest Common Ancestor")
    print("Input tree:", values)
    print("p =", p_value)
    print("q =", q_value)
    print("Lowest Common Ancestor =", answer.val)