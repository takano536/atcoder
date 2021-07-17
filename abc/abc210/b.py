n = int(input())
s = input()

for i in range(n):
    if s[i] == '1':
        print('Aoki' if i % 2 else 'Takahashi')
        quit()
