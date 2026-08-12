def search_optimized(nums, target):
    left = 0
    right = len(nums) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if nums[mid] == target:
            return mid

        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1

    return -1


print("Search in Rotated Sorted Array")
print("Optimized Modified Binary Search")

nums = [4, 5, 6, 7, 0, 1, 2]
target = 0

result = search_optimized(nums, target)

print("Array  :", nums)
print("Target :", target)
print("Result :", result)