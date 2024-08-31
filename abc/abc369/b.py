NA = -1

n = int(input())
queries = [(int(a), s) for a, s in [input().split() for _ in range(n)]]

ans = 0
curr_l = NA
curr_r = NA

for a, s in queries:
    if curr_l == NA and s == 'L':
        curr_l = a
    if curr_r == NA and s == 'R':
        curr_r = a
    if s == 'L':
        ans += abs(curr_l - a)
        curr_l = a
    if s == 'R':
        ans += abs(curr_r - a)
        curr_r = a

print(ans)
