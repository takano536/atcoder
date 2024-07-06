a, b, c, d, e, f = map(int, input().split())
g, h, i, j, k, l = map(int, input().split())

x1_min, x1_max = min(a, d), max(a, d)
y1_min, y1_max = min(b, e), max(b, e)
z1_min, z1_max = min(c, f), max(c, f)
x2_min, x2_max = min(g, j), max(g, j)
y2_min, y2_max = min(h, k), max(h, k)
z2_min, z2_max = min(i, l), max(i, l)

x_overlap = max(0, min(x1_max, x2_max) - max(x1_min, x2_min))
y_overlap = max(0, min(y1_max, y2_max) - max(y1_min, y2_min))
z_overlap = max(0, min(z1_max, z2_max) - max(z1_min, z2_min))
print('Yes' if x_overlap * y_overlap * z_overlap > 0 else 'No')
