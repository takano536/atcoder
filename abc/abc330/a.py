n, l = map(int, input().split())
a = list(map(int, input().split()))
print(sum([score >= l for score in a]))
