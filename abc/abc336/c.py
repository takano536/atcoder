n = int(input()) - 1
ans = list()

while True:
    ans.append(str((n % 5) * 2))
    n //= 5
    if n <= 0:
        break

print(''.join(reversed(ans)))
