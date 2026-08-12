def containsNearbyDuplicate(nums, k):
    n = len(nums)

    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] == nums[j] and abs(i - j) <= k:
                return True

    return False


# Test Case
nums = [1, 2, 3, 1]
k = 3

print("Input:", nums)
print("k =", k)
print("Output:", containsNearbyDuplicate(nums, k))