import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    E,N = map(int, input().rstrip("\n").split())
    empty = 0
    for _ in range(N):
        func = int(input().rstrip("\n"))
        if(func > E):
            empty+=1
    print(f"{empty}\n")