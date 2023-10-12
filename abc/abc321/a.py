n = input()

satisfied = True
for i in range(len(n) - 1):
    if int(n[i]) <= int(n[i + 1]):
        satisfied = False
        break

print("Yes" if satisfied else "No")
