import numpy as np

a = np.array(list(map(int, input().split())))
b = np.array(list(map(int, input().split())))
c = np.array(list(map(int, input().split())))
d = np.array(list(map(int, input().split())))

is_crossed = \
    (np.cross(a - c, a - b) * np.cross(a - c, a - d) < 0) & \
    (np.cross(b - d, b - a) * np.cross(b - d, b - c) < 0)

print('Yes' if is_crossed else 'No')
