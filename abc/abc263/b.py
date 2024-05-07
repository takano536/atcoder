n = int(input())
p = [pi - 1 for pi in map(int, input().split())]
curr = p[-1]
ans = 1
while curr != 0:
    ans += 1
    curr = p[curr - 1]
print(ans)
