import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input().rstrip("\n"))
if(N%2!=0): print("Either")
elif(N%4==0): print("Even")
else: print("Odd")
