n = int(input())
s = list(map(int, input().split()))

ans = 0
for guess in s:
    is_wrong = True
    for a in range(1, 500):
        for b in range(1, 500):
            if 4 * a * b + 3 * (a + b) == guess:
                is_wrong = False
    ans += int(is_wrong)
print(ans)
