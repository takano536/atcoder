k, g, m = map(int, input().split())

glass, mug = 0, 0
for _ in range(k):
    if glass == g:
        glass = 0
    elif mug == 0:
        mug = m
    else:
        if mug >= (g - glass):
            mug -= (g - glass)
            glass = g
        else:
            glass += mug
            mug = 0

print(f'{glass} {mug}')
