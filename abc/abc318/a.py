n, m, p = map(int, input().split())
print(0 if n - m < 0 else 1 + (n - m) // p)
