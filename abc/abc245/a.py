a, b, c, d = [num.zfill(2) for num in input().split()]
print('Takahashi' if int(a + b) < int(c + d) or int(a + b) == int(c + d) else 'Aoki')
