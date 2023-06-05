s, t, x = map(int, input().split())

time = s
satisfies = False
while time != t:
    if time == x:
        satisfies = True
    time = (time + 1) % 24

print('Yes' if satisfies else 'No')
