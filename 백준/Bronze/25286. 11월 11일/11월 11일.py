import sys
input = sys.stdin.readline
write = sys.stdout.write

day_30 = [4,6,9,11]

test = int(input().rstrip("\n"))
for _ in range(test):
     year, month = map(int, input().rstrip("\n").split())
     day = month
     if(month == 1):
          year -=1
          month = 12
          day = 31
     elif(month == 3):
          month -=1
          if((year%4==0 and year % 100 !=0) or year%400 == 0):
               day = 29
          else:
               day = 28
     else:
          month -=1
          if(month in day_30):
               day = 30
          else:
               day = 31
     write(f"{year} {month} {day}\n")