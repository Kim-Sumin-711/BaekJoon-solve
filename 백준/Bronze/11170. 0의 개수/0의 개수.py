import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    N,M = map(int, input().rstrip("\n").split())
    zero_cnt = 0
    for target in range(N,M+1):
        string = str(target)
        for char in string:
            if(char == '0'):
                zero_cnt+=1
    print(f"{zero_cnt}\n")