NA = -1

n, m = map(int, input().split())
s = [list(input()) for _ in range(n)]
t = [list(input()) for _ in range(m)]

ans = [NA, NA]
for i in range(n):
    for j in range(n):
        if i + m > n or j + m > n:
            continue
        is_match = True
        for k in range(m):
            for l in range(m):
                if s[i + k][j + l] != t[k][l]:
                    is_match = False
                    break
            if not is_match:
                break
        if is_match:
            ans = [i + 1, j + 1]
            break
    if is_match:
        break

print(*ans)
