INF = int(1e9)

n = int(input())
q = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = 0
for a_cnt in range(max(q) + 1):
    b_cnt = INF
    is_possible = True
    for i in range(n):
        if q[i] < a_cnt * a[i]:
            is_possible = False
            break
        if b[i] != 0:
            b_cnt = min(b_cnt, (q[i] - a_cnt * a[i]) // b[i])
    if is_possible:
        ans = max(ans, a_cnt + b_cnt)

print(ans)
