n, m = map(int, input().split())
s = [input()[-3:] for _ in range(n)]
t = [input() for _ in range(m)]
print(sum(1 for num in s if num in t))