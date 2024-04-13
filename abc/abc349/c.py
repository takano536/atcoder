s = input()
t = input().lower()
i = s.find(t[0])
j = s[i + 1:].find(t[1])
if t[2] != 'x':
    k = s[i + j + 2:].find(t[2])
else:
    k = j
print("Yes" if i != -1 and j != -1 and k != -1 else "No")
