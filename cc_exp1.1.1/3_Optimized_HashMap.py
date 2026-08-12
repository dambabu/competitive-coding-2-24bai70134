def containsNearbyDuplicate(nums, k):
    seen = {}

    for i, num in enumerate(nums):
        if num in seen and i - seen[num] <= k:
            return True

        seen[num] = i

    return False


# Test Case
nums = [1, 2, 3, 1]
k = 3

print("Input:", nums)
print("k =", k)
print("Output:", containsNearbyDuplicate(nums, k))