s = input()
satisfied = all([c.islower() for c in s[1:len(s) + 1]])
print('Yes' if satisfied and s[0].isupper() else 'No')
