n = int(input())
down = n - (n % 5)
up = n - (n % 5) + 5
if up - n < n - down:
    print(up)
else:
    print(down)
