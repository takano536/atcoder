s = input() + '.'
t = input()

for i, chars in enumerate(zip(s, t)):
    si, ti = chars
    if si != ti:
        print(i + 1)
        break
