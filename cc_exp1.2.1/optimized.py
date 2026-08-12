# Search Insert Position
# Optimized Binary Search
# Time: O(log n)
# Space: O(1)

def search_insert(nums, target):

    left = 0
    right = len(nums) - 1

    while left <= right:

        mid = left + (right - left) // 2

        if nums[mid] == target:
            return mid

        elif nums[mid] < target:
            left = mid + 1

        else:
            right = mid - 1

    return left


# Test case
nums = [1, 3, 5, 6]
target = 5

result = search_insert(nums, target)

print("Input:", nums)
print("Target:", target)
print("Insert Position:", result)