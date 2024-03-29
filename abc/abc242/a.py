a, b, c, x = map(int, input().split())
if x <= a:
    ans = 1
elif a + 1 <= x <= b:
    ans = c / (b - (a + 1) + 1)
else:
    ans = 0
print('{:.8f}'.format(ans))
