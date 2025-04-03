import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    numbers = list(map(int,input().rstrip("\n").split()))
    sum = 0
    for num in numbers:
        sum += num
    print(f"{sum}\n")