q = int(input())
is_playing = False
volume = 0
ans = [''] * q
for i in range(q):
    a = int(input())
    if a == 1:
        volume += 1
    elif a == 2:
        volume = max(volume - 1, 0)
    else:
        is_playing = not is_playing
    ans[i] = 'Yes' if volume >= 3 and is_playing else 'No'
print(*ans, sep='\n')
