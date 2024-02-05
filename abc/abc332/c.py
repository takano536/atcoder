n, m = map(int, input().split())
s = input()

cycles = s.split('0')
logo_min = max([cycle.count('2') for cycle in cycles])
total_min = max([cycle.count('1') + cycle.count('2') for cycle in cycles])
print(logo_min + max(total_min - m - logo_min, 0))
