n, a, b = map(int, input().split())

ans = 0
for i in range(1, n + 1):
    digit_sum = 0
    for digit in str(i):
        digit_sum += int(digit)
    if a <= digit_sum <= b:
        ans += i

print(ans)
