n = int(input())
s = input()
chunks = s.split('/')
if len(chunks) != 2:
    print('No')
    quit()
if len(chunks[0]) != len(chunks[1]):
    print('No')
    quit()
if chunks[0] != '1' * len(chunks[0]):
    print('No')
    quit()
if chunks[1] != '2' * len(chunks[1]):
    print('No')
    quit()
print('Yes')
