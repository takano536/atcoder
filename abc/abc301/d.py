s = input()
n = int(input())

ans = 0
for i, digit in enumerate(reversed(list(s))):
    if digit == '1':
        ans += 2 ** i

if ans > n:
    print(-1)
    quit()

s_len = len(s)
for i, digit in enumerate(list(s)):
    if digit == '?' and ans + 2 ** (s_len - i - 1) <= n:
        ans += 2 ** (s_len - i - 1)

print(ans)
