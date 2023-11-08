b = int(input())
for a in range(1, 32):
    if a ** a == b:
        print(a)
        quit()
print(-1)
