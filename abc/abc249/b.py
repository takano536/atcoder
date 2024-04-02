s = input()
is_duplicate = False
contains_upper = False
contains_lower = False
for c in list(range(ord('A'), ord('Z') + 1)) + list(range(ord('a'), ord('z') + 1)):
    if s.count(chr(c)) > 1:
        is_duplicate = True
    if s.count(chr(c)) > 0 and ord('A') <= c <= ord('Z'):
        contains_upper = True
    if s.count(chr(c)) > 0 and ord('a') <= c <= ord('z'):
        contains_lower = True
print('Yes' if not is_duplicate and contains_upper and contains_lower else 'No')
