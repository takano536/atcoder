n, k = map(int, input().split())
s = [input() for _ in range(n)]
print('\n'.join(sorted(s[:k])))