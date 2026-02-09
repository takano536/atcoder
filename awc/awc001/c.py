n, k = map(int, input().split())
d = sorted((map(int, input().split())), reverse=True)
print(sum(d) - sum(d[0:k]))
