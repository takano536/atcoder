l, r = [int(x) - 1 for x in input().split()]
s = input()
ans = s[:l]
ans += ''.join(list(reversed(list(s[l:r + 1]))))
ans += s[r + 1:]
print(ans)
