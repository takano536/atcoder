n, l, r = map(int, input().split())
ans = list(range(1, l))
ans += list(range(r, l - 1, -1))
ans += list(range(r + 1, n + 1))
print(*ans)
