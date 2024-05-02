import datetime

time = dt1 = datetime.datetime(year=2024, month=7, day=2, hour=21)
print((time + datetime.timedelta(minutes=int(input()))).strftime('%H:%M'))
