# Search Insert Position
# Brute Force Approach - O(n)

nums = [1, 3, 5, 6]
target = 5

for i in range(len(nums)):

    if nums[i] >= target:
        print("Input:", nums)
        print("Target:", target)
        print("Insert Position:", i)
        break
else:
    print("Input:", nums)
    print("Target:", target)
    print("Insert Position:", len(nums))