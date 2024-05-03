s = input()
chars = [chr(ord('a') + i) for i in range(26) if s.count(chr(ord('a') + i)) == 1]
print(-1 if len(chars) == 0 else chars[0])
