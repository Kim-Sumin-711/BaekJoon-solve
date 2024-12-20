import sys
input = sys.stdin.readline
print = sys.stdout.write
a = int(input().rstrip("\n"))
b = int(input().rstrip("\n"))
c = int(input().rstrip("\n"))

print(f"{a+b-c}\n")
tmp = f"{a}{b}"
print(f"{int(tmp) - c}")
