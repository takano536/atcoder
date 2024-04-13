s = input()
cnts = dict()
for c in s:
    cnts[c] = cnts.get(c, 0) + 1

is_satisfied = True
for i in range(len(s)):
    cnt = 0
    for _, value in cnts.items():
        if value == i + 1:
            cnt += 1
    if cnt != 0 and cnt != 2:
        is_satisfied = False

print("Yes" if is_satisfied else "No")
