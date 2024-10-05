s = input()
t = input()

for i in range(min(len(s), len(t))):
    if s[i] != t[i]:
        print(i + 1)
        exit()
print(0 if len(s) == len(t) else min(len(s), len(t)) + 1)
