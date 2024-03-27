n = int(input())
h = list(map(int, input().split()))
ans = h[0]
for next in h[1:]:
    if ans < next:
        ans = next
        continue
    break
print(ans)
