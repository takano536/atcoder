import random

R = random.randint(0, 1 << 60)
coord = [(int(x), int(y)) for x, y in [input().split() for _ in range(3)]]
x_cnts, y_cnts = dict(), dict()
for x, y in coord:
    x_cnts[x ^ R] = x_cnts[x ^ R] + 1 if x ^ R in x_cnts.keys() else 1
    y_cnts[y ^ R] = y_cnts[y ^ R] + 1 if y ^ R in y_cnts.keys() else 1
ans_x = [x for x, cnt in x_cnts.items() if cnt == 1][0]
ans_y = [y for y, cnt in y_cnts.items() if cnt == 1][0]
print(ans_x ^ R, ans_y ^ R, sep=' ')
