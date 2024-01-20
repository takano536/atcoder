def print_no():
    print('No')
    quit()


s = input()

for i in range(len(s) - 1):
    if ord(s[i]) > ord(s[i + 1]):
        print_no()

print('Yes')
