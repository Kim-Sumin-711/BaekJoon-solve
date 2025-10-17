import sys
input = sys.stdin.readline
print = sys.stdout.write

a,b = input().rstrip("\n").split()
print(f"{int(a) * int(b)}")