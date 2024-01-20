n = int(input())
t, a = 0, 0
for i in range(n):
    x, y = map(int, input().split())
    t += x
    a += y
if t == a:
    print('Draw')
else:
    print('Takahashi' if t > a else 'Aoki')
