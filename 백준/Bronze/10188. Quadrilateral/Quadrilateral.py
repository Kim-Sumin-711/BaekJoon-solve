import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    col, row = map(int,input().rstrip("\n").split())
    for r in range(row):
        for c in range(col):
            print("X")
        print("\n")
    print("\n")
