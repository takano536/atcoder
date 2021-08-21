n = int(input())
for ans in range(1000000):
    if pow(2, ans) > n:
        print(ans - 1)
        quit()
