n = input()
s = input()

dict = dict()
dict['A'] = 0
dict['B'] = 0
dict['C'] = 0
for i, c in enumerate(s):
    dict[c] += 1
    if dict['A'] > 0 and dict['B'] > 0 and dict['C'] > 0:
        print(i + 1)
        quit()
