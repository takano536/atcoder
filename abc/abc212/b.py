x = input()

ok = False
for i in range(len(x) - 1):
    if x[i] != x[i + 1]:
        ok = True
if not ok:
    print('Weak')
    quit()

is_sequence = True
for i in range(len(x) - 1):
    if int(x[i]) % 10 != (int(x[i + 1]) - 1) % 10:
        is_sequence = False
if (is_sequence):
    print('Weak')
    quit()

print('Strong')
