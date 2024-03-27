n = int(input())
a = list(map(int, input().split()))
cnts = [[0, 0] for _ in range(n)]
for ai in a:
    cnts[ai - 1][1] = ai
    cnts[ai - 1][0] += 1
print(sorted(cnts)[0][1])
