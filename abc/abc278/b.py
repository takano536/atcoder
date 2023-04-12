h, m = input().split()

while True:
    h, m = [s.zfill(2) for s in [h, m]]
    swap_h, swap_m = map(int, [h[0] + m[0], h[1] + m[1]])
    if swap_h < 24 and swap_m < 60:
        print(h, m)
        quit()

    m = str(int(m) + 1)
    if m == '60':
        m = '00'
        h = str(int(h) + 1)
    if h == '24':
        h = '00'
