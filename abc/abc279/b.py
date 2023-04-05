s = input()
t = input()

satisfies = s == t
for i in range(len(s) - len(t) + 1):
    if s[i:i + len(t)] == t:
        satisfies = True
    
print('Yes' if satisfies else 'No')