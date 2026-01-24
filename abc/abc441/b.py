n, m = map(int, input().split())
s = input()
t = input()

for _ in range(int(input())):
    unknown = True
    for wi in input():
        if wi not in s:
            print('Aoki')
            unknown = False
            break
        if wi not in t:
            print('Takahashi')
            unknown = False
            break
    if unknown:
        print('Unknown')
