import sys
n,m = map(int,sys.stdin.readline().rstrip("\n").split())
sys.stdout.write(f"{n//m}\n{n%m}")