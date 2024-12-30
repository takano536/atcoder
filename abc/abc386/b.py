def rle(s: str) -> tuple[tuple[str, int]]:
    ret = list()
    curr = [s[0], 1]
    for c in s[1:]:
        if c == curr[0]:
            curr[1] += 1
        else:
            ret.append(tuple(curr))
            curr = [c, 1]
    ret.append(tuple(curr))
    return ret


s = input()
ans = 0
for c, num in rle(s):
    ans += ((num + 2 - 1) // 2 if c == '0' else num)
print(ans)
