a = list()
while True:
    try:
        a.append(int(input()))
    except EOFError:
        break
reversed_a = list(reversed(a))
print('\n'.join(map(str, reversed_a)))
