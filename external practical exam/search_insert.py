
# LeetCode Problem 35: Search Insert Position

def searchInsert(nums, target):
    left = 0
    right = len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            return mid

        elif nums[mid] < target:
            left = mid + 1

        else:
            right = mid - 1

    return left


# Main Program
nums = [1, 3, 5, 6]
target = 2

answer = searchInsert(nums, target)

print("Given Array:", nums)
print("Target Element:", target)
print("Insert Position:", answer)
