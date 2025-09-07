t = int(input())
ans = [0] * t
for i in range(t):
    a, b, c = map(int, input().split())
    ans[i] = min(a, c, (a + b + c) // 3)
print(*ans, sep='\n')
