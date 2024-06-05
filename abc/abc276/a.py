s = ''.join(reversed(input()))
print(len(s) - s.find('a') if s.count('a') > 0 else -1)
