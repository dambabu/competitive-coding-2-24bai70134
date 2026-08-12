def largest_rectangle_optimized(heights):
    stack = []
    max_area = 0

    heights.append(0)

    for i in range(len(heights)):

        while stack and heights[stack[-1]] > heights[i]:
            height = heights[stack.pop()]

            left = stack[-1] if stack else -1
            width = i - left - 1

            area = height * width

            if area > max_area:
                max_area = area

        stack.append(i)

    heights.pop()

    return max_area


print("Largest Rectangle in Histogram")
print("Optimized Monotonic Stack")

heights = [2, 1, 5, 6, 2, 3]

result = largest_rectangle_optimized(heights)

print("Heights:", heights)
print("Maximum Area:", result)