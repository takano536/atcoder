s = input()

if s[0] == '1':
    print('No')
    quit()

has_knocked_down = [
    [s[6] == '0'],
    [s[3] == '0'],
    [s[7] == '0', s[1] == '0'],
    [s[4] == '0', s[0] == '0'],
    [s[8] == '0', s[2] == '0'],
    [s[5] == '0'],
    [s[9] == '0']
]
hasnt_knocked_down = [
    [s[6] == '1'],
    [s[3] == '1'],
    [s[7] == '1', s[1] == '1'],
    [s[4] == '1', s[0] == '1'],
    [s[8] == '1', s[2] == '1'],
    [s[5] == '1'],
    [s[9] == '1']
]

N = 7

for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            if not any(hasnt_knocked_down[i]):
                continue
            if not all(has_knocked_down[j]):
                continue
            if not any(hasnt_knocked_down[k]):
                continue
            print('Yes')
            quit()

print('No')
