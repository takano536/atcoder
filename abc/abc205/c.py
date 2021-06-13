a, b, c = map(int, input().split())
if c % 2:
    if a == b:
        print('=')
    else:
        print('>' if a > b else '<')
else:
    if abs(a) == abs(b):
        print('=')
    else:
        print('>' if abs(a) > abs(b) else '<')
