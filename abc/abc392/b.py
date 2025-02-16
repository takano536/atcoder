n, m = map(int, input().split())
a = set(map(int, input().split()))
print(n - m)
for i in range(n):
    if i + 1 not in a:
        print(i + 1, end=' ')
print()
