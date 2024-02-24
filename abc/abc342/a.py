s = input()
cnts = dict()
for c in s:
    if c in cnts:
        cnts[c] += 1
    else:
        cnts[c] = 1

sorted_cnts = sorted(cnts.items(), key=lambda x: x[1], reverse=True)
min_char = sorted_cnts[-1][0]

for i, c in enumerate(s):
    if c == min_char:
        print(i + 1)
