n, k = map(int, input().split())
s = input()

counts = dict()
for i in range(n - k + 1):
    if s[i:i + k] in counts:
        counts[s[i:i + k]] += 1
    else:
        counts[s[i:i + k]] = 1

ans = max(counts.values())
words = [word for word, count in counts.items() if count == ans]

print(ans)
print(*sorted(words))
