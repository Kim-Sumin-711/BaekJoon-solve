import sys
input = sys.stdin.readline
print = sys.stdout.write

time = int(input().rstrip("\n"))
A,B,C=300,60,10
if(time%10!=0):
    print("-1")
else:
    print(f"{time//A} ")
    time-=A*(time//A)
    print(f"{time//B} ")
    time-=B*(time//B)
    print(f"{time//C}")
