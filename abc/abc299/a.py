n = input()
s = input()
print('in' if s.find('|') < s.find('*') < s.rfind('|') else 'out')
