import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    price = float(input().rstrip("\n"))
    temp = round(price*0.8,2)
    print(f"${temp:.2f}\n")
