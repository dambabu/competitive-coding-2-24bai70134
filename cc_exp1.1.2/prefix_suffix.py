# Product of Array Except Self
# Prefix + Suffix Approach
# O(n) Time and O(n) Space

nums = [1, 2, 3, 4]

n = len(nums)

prefix = [1] * n
suffix = [1] * n
answer = [1] * n

# Calculate prefix products
for i in range(1, n):
    prefix[i] = prefix[i - 1] * nums[i - 1]

# Calculate suffix products
for i in range(n - 2, -1, -1):
    suffix[i] = suffix[i + 1] * nums[i + 1]

# Multiply prefix and suffix
for i in range(n):
    answer[i] = prefix[i] * suffix[i]

print("Input:", nums)
print("Prefix:", prefix)
print("Suffix:", suffix)
print("Output:", answer)