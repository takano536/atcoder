s = input()
t = input()

s_char_cnts = dict()
t_char_cnts = dict()

WILDCARDS = 'atcoder'

for c in s:
    s_char_cnts[c] = s_char_cnts.get(c, 0) + 1
for c in t:
    t_char_cnts[c] = t_char_cnts.get(c, 0) + 1

satisfies = True
for c in range(97, 123):
    c = chr(c)

    if s_char_cnts.get(c, 0) == t_char_cnts.get(c, 0):
        continue

    if c not in WILDCARDS:
        satisfies = False
        break

    if s_char_cnts.get(c, 0) > t_char_cnts.get(c, 0):
        shortage = s_char_cnts.get(c, 0) - t_char_cnts.get(c, 0)
        t_char_cnts['@'] = t_char_cnts.get('@', 0) - shortage
        if t_char_cnts['@'] < 0:
            satisfies = False
            break

    if s_char_cnts.get(c, 0) < t_char_cnts.get(c, 0):
        shortage = t_char_cnts.get(c, 0) - s_char_cnts.get(c, 0)
        s_char_cnts['@'] = s_char_cnts.get('@', 0) - shortage
        if s_char_cnts['@'] < 0:
            satisfies = False
            break

print('Yes' if satisfies else 'No')
