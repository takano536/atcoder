ages = [0] * 3
s = input().split()

ages[(0 if s[0] == '>' else 1)] += 1
ages[(0 if s[1] == '>' else 2)] += 1
ages[(1 if s[2] == '>' else 2)] += 1

print(chr(ages.index(1) + ord('A')))
