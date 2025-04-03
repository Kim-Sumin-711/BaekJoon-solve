import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    m,n = map(int,input().rstrip("\n").split())
    print(f"You get {m//n} piece(s) and your dad gets {m%n} piece(s).\n")