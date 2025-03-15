x = input()
temp = x.split('.')
temp = int(temp[0] + temp[1])
if temp >= 380:
    print(1)
elif 375 <= temp < 380:
    print(2)
else:
    print(3)
