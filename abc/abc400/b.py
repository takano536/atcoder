n, m = map(int, input().split())
if n == 1:
    print(1 * (m + 1))
    exit()

if m > 30:
    print('inf')
    exit()

ans = 0
for i in range(m + 1):
    ans += n ** i
print(ans if ans <= 1e9 else 'inf')
