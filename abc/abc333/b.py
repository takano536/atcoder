s = input()
t = input()

s_dist = 2
if abs(ord(s[0]) - ord(s[1])) == 1 or (s[0] == 'A' and s[1] == 'E') or (s[0] == 'E' and s[1] == 'A'):
    s_dist = 1
t_dist = 2
if abs(ord(t[0]) - ord(t[1])) == 1 or (t[0] == 'A' and t[1] == 'E') or (t[0] == 'E' and t[1] == 'A'):
    t_dist = 1

print('Yes' if s_dist == t_dist else 'No')
