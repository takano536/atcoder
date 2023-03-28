n, m = map(int, input().split())
a = list(map(int, input().split()))
b = [int(s) - 1 for s in input().split()]
print(sum([a[i] for i in b]))