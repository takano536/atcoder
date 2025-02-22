n = int(input())
s = list()
for i in range(n):
    si = input()
    s.append((len(si), si))
print(''.join([si for _, si in sorted(s)]))
