def largest_rectangle(heights):
    heights.append(0)

    stack = []
    max_area = 0

    for i, height in enumerate(heights):

        while stack and heights[stack[-1]] > height:
            h = heights[stack.pop()]

            left = stack[-1] if stack else -1
            width = i - left - 1

            area = h * width

            if area > max_area:
                max_area = area

        stack.append(i)

    heights.pop()

    return max_area


print("Largest Rectangle in Histogram")
print("Monotonic Stack Approach")

heights = [2, 1, 5, 6, 2, 3]

result = largest_rectangle(heights)

print("Heights:", heights)
print("Maximum Area:", result)