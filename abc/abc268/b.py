s = input()
t = input()
if len(s) > len(t):
    print('No')
    quit()
print('Yes' if t[0:len(s)] == s else 'No')
