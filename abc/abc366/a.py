n, t, a = map(int, input().split())
print('Yes' if max(t, a) >= (n + 1) // 2 else 'No')
