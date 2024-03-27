n, k = map(int, input().split())
a = {int(num) for num in input().split() if int(num) <= k}
ans = int(k * (k + 1) // 2)
print(ans - sum(a))
