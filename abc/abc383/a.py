n = int(input())
ans = 0
curr_t = 0
for _ in range(n):
    t, v = map(int, input().split())
    ans = max(ans - (t - curr_t), 0) + v
    curr_t = t
print(ans)
