s = input()
if s[0].isnumeric() or s[-1].isnumeric() or not s[1:-1].isnumeric():
    print('No')
    quit()
print('Yes' if 100000 <= int(s[1:-1]) <= 999999 and len(s[1:-1]) == 6 else 'No')
