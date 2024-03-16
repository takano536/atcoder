s = input()
satisfied = True
if s[0] != '<':
    satisfied = False
if s[-1] != '>':
    satisfied = False
if s[1:-1].count('=') != len(s[1:-1]):
    satisfied = False
print('Yes' if satisfied else 'No')
