n, x = map(int, input().split())
a = list(map(int, input().split()))

ans = 101
for i in range(100 + 1):
    scores = a.copy()
    scores.append(i)
    scores.sort()
    if sum(scores[1:n-1]) >= x:
        ans = min(ans, i)

print(ans if ans != 101 else -1)
