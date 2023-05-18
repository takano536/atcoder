n = int(input())
c, s, f = [list(inputs) for inputs in zip(*[map(int, input().split()) for _ in range(n - 1)])]

for start_idx in range(n):
    ans = 0
    for curr_idx in range(start_idx, n - 1):
        ans = max(s[curr_idx], ans)
        if ans % f[curr_idx] != 0:
            ans += f[curr_idx] - ans % f[curr_idx]
        ans += c[curr_idx]
    print(ans)