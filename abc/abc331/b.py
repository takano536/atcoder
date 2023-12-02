s_size, m_size, l_size = 6, 8, 12
n, s, m, l = map(int, input().split())

ans = 1e18
for i in range(n + 1):
    for j in range(n + 1):
        for k in range(n + 1):
            if i * s_size + j * m_size + k * l_size >= n:
                ans = min(ans, i * s + j * m + k * l)

print(ans)
