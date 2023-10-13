import math
h, w = map(int, input().split())
print(h * w if h == 1 or w == 1 else math.ceil(h / 2) * math.ceil(w / 2))
