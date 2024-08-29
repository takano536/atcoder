n = int(input())
a = sorted(list(map(int, input().split())), reverse=True)

ans = 0
while a[0] != 0 and a[1] != 0:
    a[0] -= 1
    a[1] -= 1
    ans += 1
    a.sort(reverse=True)

print(ans)
