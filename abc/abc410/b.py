n, q = map(int, input().split())
boxes = [[0, i] for i in range(n)]
ans = [0] * q
for i, x in enumerate(map(int, input().split())):
    if x > 0:
        ans[i] = x
        boxes[x - 1][0] += 1
        continue
    _, index = min(boxes)
    ans[i] = index + 1
    boxes[index][0] += 1

print(*ans, sep=' ')
