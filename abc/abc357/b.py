s = input()

upper_cnt = 0
for c in s:
    if c.isupper():
        upper_cnt += 1

print(s.upper() if upper_cnt > len(s) // 2 else s.lower())
