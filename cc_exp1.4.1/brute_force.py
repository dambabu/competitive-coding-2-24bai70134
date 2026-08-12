class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def is_palindrome_brute_force(head):
    values = []
    current = head

    while current:
        values.append(current.val)
        current = current.next

    left = 0
    right = len(values) - 1

    while left < right:
        if values[left] != values[right]:
            return False

        left += 1
        right -= 1

    return True


def create_linked_list(values):
    if not values:
        return None

    head = ListNode(values[0])
    current = head

    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next

    return head


print("Palindrome Linked List")
print("Brute Force Approach")

values = [1, 2, 2, 1]

head = create_linked_list(values)

result = is_palindrome_brute_force(head)

print("Linked List:", values)
print("Palindrome:", result)