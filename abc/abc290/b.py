n, k = map(int, input().split())
s = input()

ans = list(s)
passing_cnt = 0
for i, c in enumerate(ans):
    if c == 'x':
        continue

    passing_cnt += 1
    ans[i] = 'x' if passing_cnt > k else 'o'

print(''.join(ans))