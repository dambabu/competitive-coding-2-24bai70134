def containsNearbyDuplicate(nums, k):
    n = len(nums)

    # Check every window of size k+1
    for i in range(n):
        window = nums[i:min(i + k + 1, n)]

        if len(window) != len(set(window)):
            return True

    return False


# Test Case
nums = [1, 2, 3, 1]
k = 3

print("Input:", nums)
print("k =", k)
print("Output:", containsNearbyDuplicate(nums, k))