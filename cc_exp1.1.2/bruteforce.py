# Product of Array Except Self
# Brute Force Approach - O(n^2)

nums = [1, 2, 3, 4]

n = len(nums)
answer = [1] * n

for i in range(n):
    product = 1

    for j in range(n):
        if i != j:
            product *= nums[j]

    answer[i] = product

print("Input:", nums)
print("Output:", answer)