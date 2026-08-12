def search_brute_force(nums, target):
    for i in range(len(nums)):
        if nums[i] == target:
            return i

    return -1


print("Search in Rotated Sorted Array")
print("Brute Force Approach")

nums = [4, 5, 6, 7, 0, 1, 2]
target = 0

result = search_brute_force(nums, target)

print("Array  :", nums)
print("Target :", target)
print("Result :", result)