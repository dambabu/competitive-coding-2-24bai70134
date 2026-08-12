class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def is_palindrome(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    previous = None
    current = slow

    while current:
        next_node = current.next
        current.next = previous
        previous = current
        current = next_node

    first = head
    second = previous

    while second:
        if first.val != second.val:
            return False

        first = first.next
        second = second.next

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
print("Optimized Approach")

values = [1, 2, 2, 1]

head = create_linked_list(values)
result = is_palindrome(head)

print("Linked List:", values)
print("Palindrome:", result)