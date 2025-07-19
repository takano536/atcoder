s = input()

NA = -1

ans = list()
curr = [NA, NA]
for i, c in enumerate(s):
    if c == '.':
        continue

    if curr[0] == NA:
        curr[0] = i + 1
    elif curr[1] == NA:
        curr[1] = i + 1
        ans.append(','.join(map(str, curr)))
        curr = [NA, NA]

print(*ans, sep='\n')
