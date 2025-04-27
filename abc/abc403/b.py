t = input()
u = input()

is_contained = False
for i in range(len(t) - len(u) + 1):
    is_satisfied = True
    for j in range(len(u)):
        if t[i + j] == u[j] or t[i + j] == '?':
            continue
        is_satisfied = False
    if is_satisfied:
        is_contained = True
        break

print('Yes' if is_contained else 'No')
