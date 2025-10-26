n = int(input())
a = list(map(int, input().split()))
is_satisfied = True
nums = list(range(1, n + 1))
for i in range(1, n + 1):
    if a.count(i) > 1:
        print('No')
        quit()
    if a.count(i) == 1:
        nums.remove(i)
ans = [0] * n
for i in range(n):
    if a[i] == -1:
        ans[i] = nums[-1]
        nums.pop()
    else:
        ans[i] = a[i]
print('Yes')
print(*ans)
