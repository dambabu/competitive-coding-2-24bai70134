print("TEST")

def largest_rectangle_brute_force(heights):
    max_area = 0
    n = len(heights)

    for i in range(n):
        min_height = heights[i]

        for j in range(i, n):
            min_height = min(min_height, heights[j])
            width = j - i + 1
            area = min_height * width

            if area > max_area:
                max_area = area

    return max_area


heights = [2, 1, 5, 6, 2, 3]

result = largest_rectangle_brute_force(heights)

print("Heights:", heights)
print("Maximum Area:", result)