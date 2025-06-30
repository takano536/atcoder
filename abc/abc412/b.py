s = input()
t = input()

is_satisfied = True
for i, c in enumerate(s):
    if i == 0 or c.islower():
        continue
    if s[i - 1] not in t:
        is_satisfied = False

print('Yes' if is_satisfied else 'No')
