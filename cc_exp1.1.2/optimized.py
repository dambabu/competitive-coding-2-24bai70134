# Product of Array Except Self
# Optimized Prefix-Suffix Approach
# O(n) Time
# O(1) Extra Space

nums = [1, 2, 3, 4]

n = len(nums)

answer = [1] * n

# Left pass
for i in range(1, n):
    answer[i] = answer[i - 1] * nums[i - 1]

# Right pass
right = 1

for i in range(n - 1, -1, -1):
    answer[i] *= right
    right *= nums[i]

print("Input:", nums)
print("Output:", answer)