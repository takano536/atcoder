s = list(map(int, input().split()))
s.append(675)

satisfies = True
for i in range(len(s) - 1):
    if s[i] > s[i + 1]:
        satisfies = False
    if s[i] < 100 or s[i] > 675:
        satisfies = False
    if s[i] % 25 != 0:
        satisfies = False

print("Yes" if satisfies else "No")
