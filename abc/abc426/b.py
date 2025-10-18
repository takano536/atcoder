s = input()
ans = 'a'
for c in range(ord('z') - ord('a') + 1):
    c = chr(c + ord('a'))
    if s.count(c) == 1:
        print(c)
        break
