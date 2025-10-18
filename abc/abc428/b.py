n, k = map(int, input().split())
s = input()

counts = dict()
for i in range(n - k + 1):
    if s[i:i + k] in counts:
        counts[s[i:i + k]] += 1
    else:
        counts[s[i:i + k]] = 1

ans = 0
for v in counts.values():
    ans = max(v, ans)

words = list()
for k, v in counts.items():
    if v == ans:
        words.append(k)

print(ans)
print(*sorted(words))
