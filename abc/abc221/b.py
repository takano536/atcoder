s = list(input())
t = list(input())

if s == t:
    print('Yes')
    quit()
for i in range(len(s) - 1):
    swap = list(t)
    swap[i], swap[i + 1] = swap[i + 1], swap[i]
    if s == swap:
        print('Yes')
        quit()
print('No')
