n, m = map(int, input().split())
s = [input() for _ in range(n)]
counts = [[0, -i] for i in range(n)]

for i in range(m):
    true_count, false_count = 0, 0
    for j in range(n):
        if s[j][i] == '1':
            true_count += 1
        else:
            false_count += 1
    if true_count == 0 or false_count == 0:
        continue
    scoring_char = ('1' if true_count < false_count else '0')
    for j in range(n):
        if s[j][i] == scoring_char:
            counts[j][0] += 1

sorted_counts = sorted(counts, reverse=True)

print(sorted_counts[0][-1] * -1 + 1, end=' ')
for i in range(1, n):
    if sorted_counts[i][0] != sorted_counts[0][0]:
        break
    print(sorted_counts[i][-1] * -1 + 1, end=' ')
print('\n', end='')
