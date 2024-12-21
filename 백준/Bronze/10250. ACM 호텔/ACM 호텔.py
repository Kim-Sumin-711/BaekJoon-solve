import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))

while(test):
    test-=1
    h,w,n = map(int, input().rstrip("\n").split())
    floor = n % h
    if(not floor):
        floor = h
        ho = n // h
    else:
        ho = n // h + 1
    if(ho < 10):
        print(f"{floor}0{ho}\n")
    else:
        print(f"{floor}{ho}\n")
