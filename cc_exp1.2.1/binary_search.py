# Search Insert Position
# Binary Search Approach - O(log n)

nums = [1, 3, 5, 6]
target = 5

left = 0
right = len(nums) - 1

while left <= right:

    mid = (left + right) // 2

    if nums[mid] == target:
        print("Input:", nums)
        print("Target:", target)
        print("Insert Position:", mid)
        break

    elif nums[mid] < target:
        left = mid + 1

    else:
        right = mid - 1

else:
    print("Input:", nums)
    print("Target:", target)
    print("Insert Position:", left)