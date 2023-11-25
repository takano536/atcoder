n, l, r = map(int, input().split())
a = list(map(int, input().split()))

for num in a:
    min_diff = 0 if l <= num <= r else min(abs(l - num), abs(r - num))
    if l <= num - min_diff <= r:
        print(num - min_diff, end=' ')
    else:
        print(num + min_diff, end=' ')
print()
