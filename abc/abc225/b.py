n = int(input())
cnts = [0] * n
for _ in range(n - 1):
    a, b = [int(num) - 1 for num in input().split()]
    cnts[a] += 1
    cnts[b] += 1

print('Yes' if any([cnt == n - 1 for cnt in cnts]) else 'No')
