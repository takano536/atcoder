n = int(input())
ans = (1, 0)
for i in range(n + 1):
    if i % 2 != 0:
        continue
    cnt = 0
    curr_num = i
    while i % 2 == 0 and i > 0:
        i //= 2
        cnt += 1
    if cnt > ans[1]:
        ans = (curr_num, cnt)

print(ans[0])
