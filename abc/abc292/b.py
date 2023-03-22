n, q = map(int, input().split())
penalty_count = [0] * n
for _ in range(q):
    e, x = map(int, input().split())
    x = x - 1
    if e == 1:
        penalty_count[x] += 1
    elif e == 2:
        penalty_count[x] += 2
    else:
        print("Yes" if penalty_count[x] >= 2 else "No")
