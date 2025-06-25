s = input()

is_satisfied = True
is_satisfied &= s[0] == 'A'
is_satisfied &= s.count('C', 2, -1) == 1
is_satisfied &= sum((c.isupper() for c in s)) == 2

print('AC' if is_satisfied else 'WA')
