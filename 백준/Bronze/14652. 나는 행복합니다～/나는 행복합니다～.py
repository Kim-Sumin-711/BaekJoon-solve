import sys
input = sys.stdin.readline
print = sys.stdout.write

n,m,target = map(int,input().rstrip("\n").split())

row = target // m
col = target - m*row
print(f"{row} {col}")