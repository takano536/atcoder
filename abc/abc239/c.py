x1, y1, x2, y2 = map(int, input().split())
VECS = ((1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-1, 2), (-2, 1))
is_satisfied = False
for [x_vec, y_vec] in VECS:
    x_center = x1 + x_vec
    y_center = y1 + y_vec
    x_diff = x2 - x_center
    y_diff = y2 - y_center
    is_satisfied |= x_diff ** 2 + y_diff ** 2 == 5
print('Yes' if is_satisfied else 'No')
