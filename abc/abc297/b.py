s = input()

satisfies = True
if s.find('B') % 2 == s.rfind('B') % 2:
    satisfies = False
if not s.find('R') < s.find('K') < s.rfind('R'):
    satisfies = False

print('Yes' if satisfies else 'No')
