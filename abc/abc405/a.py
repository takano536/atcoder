r, x = map(int, input().split())

if x == 1:
    print("Yes" if 1600 <= r <= 2999 else "No")
elif x == 2:
    print("Yes" if 1200 <= r <= 2399 else "No")
