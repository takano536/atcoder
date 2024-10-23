n, q = map(int, input().split())

l, r = 0, 1
ans = 0
for _ in range(q):
    c, t = input().split()
    t = int(t) - 1

    cnt = 0
    is_satisfied = True
    prev_l, prev_r = l, r
    if c == 'L':
        if l == t:
            continue
        while l != t:
            l = (l - 1) % n
            cnt += 1
            if l == r:
                is_satisfied = False
                break
        if is_satisfied:
            ans += cnt
            continue
        l = prev_l
        while l != t:
            l = (l + 1) % n
            ans += 1
        l = t

    if c == 'R':
        if r == t:
            continue
        while r != t:
            r = (r + 1) % n
            cnt += 1
            if l == r:
                is_satisfied = False
                break
        if is_satisfied:
            ans += cnt
            continue
        r = prev_r
        while r != t:
            r = (r - 1) % n
            ans += 1
        r = t

print(ans)
