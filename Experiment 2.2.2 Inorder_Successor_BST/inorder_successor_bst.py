# Experiment 2.2.2
# Inorder Successor in BST
# LeetCode Problem #285


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderSuccessor(self, root, p):

        # Initially, no successor is found
        successor = None

        # Search the BST iteratively
        while root is not None:

            # If current value is less than or equal to p,
            # successor must be in the right subtree
            if p.val >= root.val:
                root = root.right

            else:
                # Current node is a possible successor
                successor = root

                # Search for a smaller valid successor
                root = root.left

        return successor


def insert(root, value):
    """Insert a value into a Binary Search Tree."""

    if root is None:
        return TreeNode(value)

    if value < root.val:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)

    return root


def find_node(root, value):
    """Find a node by its value."""

    if root is None:
        return None

    if root.val == value:
        return root

    if value < root.val:
        return find_node(root.left, value)

    return find_node(root.right, value)


def inorder(root):
    """Print the inorder traversal of the BST."""

    if root is None:
        return

    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)


# Main program
if __name__ == "__main__":

    # Construct BST using insertion
    values = [5, 3, 6, 2, 4, 1]

    root = None

    for value in values:
        root = insert(root, value)

    # Select node p
    p_value = 3
    p = find_node(root, p_value)

    solution = Solution()

    answer = solution.inorderSuccessor(root, p)

    print("Experiment 2.2.2: Inorder Successor in BST")
    print("BST values:", values)

    print("Inorder traversal: ", end="")
    inorder(root)
    print()

    print("p =", p_value)

    if answer is not None:
        print("Inorder Successor =", answer.val)
    else:
        print("Inorder Successor = None")