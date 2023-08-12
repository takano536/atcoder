n = int(input())
a = list()
c = list()
for i in range(n):
    c.append((int(input()), i))
    a.append(list(map(int, input().split())))
x = int(input())

c.sort()

ans = list()
min_num = 1e9
for num, idx in c:
    if a[idx].count(x) == 0:
        continue
    if num > min_num:
        break
    min_num = num
    ans.append(idx + 1)

print(len(ans))
for i in ans:
    print(i, end=' ')
print()
