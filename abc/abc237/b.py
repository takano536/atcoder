import numpy as np

h, w = map(int, input().split())
a = list()
for i in range(h):
    a += list(map(int, input().split()))
b = np.array(a).reshape(h, w)
for vec in b.T:
    print(' '.join(str(num) for num in vec))
