n = int(input())
a = list(map(int, input().split()))

cumsum = [0] * (n + 1)
for i in range(n):
    cumsum[i + 1] = cumsum[i] + a[i]

print(abs(min(cumsum)) + sum(a) if min(cumsum) < 0 else sum(a))
