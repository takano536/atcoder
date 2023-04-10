a, b = map(int, input().split())

ans = 0
while a != 0 and b != 0:
    if a < b:
        a, b = b, a
    ans += a // b
    a %= b

print(ans - 1)
