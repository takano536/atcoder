h, w = map(int, input().split())
s = tuple(input() for _ in range(h))


TAK_CODE = (
    '###.?????',
    '###.?????',
    '###.?????',
    '....?????',
    '?????????',
    '?????....',
    '?????.###',
    '?????.###',
    '?????.###',
)
H, W = len(TAK_CODE), len(TAK_CODE[0])


for i in range(h):
    for j in range(w):
        is_satisfied = True
        for ii in range(H):
            for jj in range(W):
                if i + ii >= h or j + jj >= w:
                    is_satisfied = False
                    continue
                if TAK_CODE[ii][jj] == '?':
                    continue
                if s[i + ii][j + jj] != TAK_CODE[ii][jj]:
                    is_satisfied = False
        if is_satisfied:
            print(f'{i + 1} {j + 1}')
