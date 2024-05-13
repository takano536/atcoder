import math

n, h = map(int, input().split())
swords = [tuple(map(int, input().split())) for _ in range(n)]
a = sorted([ai for ai, _ in swords])
b = sorted([bi for _, bi in swords], reverse=True)
swords = sorted([(ai, -bi) for ai, bi in swords])
max_a = a[-1]

ans = 8e18
cnt = 0
curr_h = 0
for bi in b:
    if bi < max_a:
        continue
    if curr_h >= h:
        break
    curr_h += bi
    cnt += 1
ans = min(cnt, ans) if curr_h >= h else min(cnt + math.ceil((h - curr_h) / max_a), ans)

print(ans)
