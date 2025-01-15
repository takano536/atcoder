n, a, b = map(int, input().split())
ans = min(n, 5) * b
n -= min(n, 5)
ans += n * a
print(ans)
