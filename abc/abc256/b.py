n = int(input())
a = list(map(int, input().split()))

curr = sum(a)
ans = 0
for ai in a:
    ans += int(curr >= 4)
    curr -= ai

print(ans)
