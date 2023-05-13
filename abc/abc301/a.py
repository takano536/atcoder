n = int(input())
s = input()

if s.count('T') != s.count('A'):
    print('T' if s.count('T') > s.count('A') else 'A')
    quit()

t_cnt = 0
a_cnt = 0
for c in s:
    if c == 'T':
        t_cnt += 1
    else:
        a_cnt += 1
    if t_cnt >= n // 2:
        print('T')
        break
    if a_cnt >= n // 2:
        print('A')
        break
