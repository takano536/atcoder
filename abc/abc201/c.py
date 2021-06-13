s = input()
maru = []
batsu = []
for i in range(10):
    if s[i] == 'o':
        maru.append(i)
    elif s[i] == 'x':
        batsu.append(i)

ans = 0
for i in range(10000):
    num = str(i).zfill(4)
    ok = True
    for n in maru:
        if num.count(str(n)) == 0:
            ok = False
    for n in batsu:
        if num.count(str(n)) > 0:
            ok = False
    if ok:
        ans += 1

print(ans)
