s = input()

rstriped_s = s.rstrip('a')
right_cnt = len(s) - len(s.rstrip('a'))
striped_s = list(reversed(list(rstriped_s)))
for _ in range(min(len(striped_s), right_cnt)):
    if striped_s[-1] == 'a':
        striped_s.pop()
    else:
        break

print('Yes' if list(reversed(striped_s)) == striped_s else 'No')
