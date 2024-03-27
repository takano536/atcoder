a, b = map(int, input().split())
ans = list(range(10))
ans.remove(a + b)
print(ans[0])
