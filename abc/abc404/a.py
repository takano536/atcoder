ans = {chr(i + ord('a')) for i in range(26)}
for c in input():
    ans.discard(c)
print(ans.pop())
