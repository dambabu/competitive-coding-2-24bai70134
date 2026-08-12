print("HELLO FROM TWO POINTER")

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def is_palindrome(values):
    left = 0
    right = len(values) - 1

    while left < right:
        if values[left] != values[right]:
            return False

        left += 1
        right -= 1

    return True


values = [1, 2, 2, 1]

result = is_palindrome(values)

print("Input:", values)
print("Result:", result)