n, t, p = map(int, input().split())
l = sorted(list(map(int, input().split())), reverse=True)
print(max(0, t - l[p - 1]))
