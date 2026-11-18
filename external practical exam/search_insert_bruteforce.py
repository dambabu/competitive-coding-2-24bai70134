
# LeetCode 35 - Search Insert Position
# Brute Force Approach

def searchInsert(nums, target):

    for i in range(len(nums)):

        if nums[i] >= target:
            return i

    return len(nums)


nums = [1, 3, 5, 6]
target = 2

result = searchInsert(nums, target)

print("Array:", nums)
print("Target:", target)
print("Brute Force Answer:", result)
