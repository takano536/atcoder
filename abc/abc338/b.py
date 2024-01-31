s = input()
counts = [0] * 26
max_count = 0
for c in s:
    counts[ord(c) - ord('a')] += 1
    max_count = max(max_count, counts[ord(c) - ord('a')])
for i in range(26):
    if counts[i] == max_count:
        print(chr(ord('a') + i))
        break
