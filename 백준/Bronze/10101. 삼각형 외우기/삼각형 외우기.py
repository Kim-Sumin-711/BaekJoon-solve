import sys
input = sys.stdin.readline
print = sys.stdout.write

a = int(input().rstrip("\n"))
b = int(input().rstrip("\n"))
c = int(input().rstrip("\n"))
if(a==b==c==60):
    print("Equilateral")
elif(a+b+c==180):
    if(a==b or b==c or c==a):
        print("Isosceles")
    else:
        print("Scalene")
else:
    print("Error")
