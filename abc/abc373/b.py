s = input()
idx = s.find('A')
ans = 0
for i in range(26):
    next = s.find(chr(ord('A') + i))
    ans += abs(idx - next)
    idx = next
print(ans)
