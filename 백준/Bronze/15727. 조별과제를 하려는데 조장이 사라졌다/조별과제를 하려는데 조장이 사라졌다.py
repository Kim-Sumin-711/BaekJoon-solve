import sys
input = sys.stdin.readline
print = sys.stdout.write

distance = int(input().rstrip("\n"))
if(distance%5==0): print(f"{distance//5}")
else: print(f"{distance//5+1}")