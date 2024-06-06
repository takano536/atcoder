n = int(input())
s = list(map(int, input().split()))
curr = s[0]
for i in range(1, n):
    s[i] -= curr
    curr += s[i]
print(*s)
