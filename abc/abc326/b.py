n = int(input())

ans = n
while True:
    n_str = str(ans)
    if int(n_str[-1]) == int(n_str[-2]) * int(n_str[-3]):
        print(ans)
        quit()
    ans += 1
