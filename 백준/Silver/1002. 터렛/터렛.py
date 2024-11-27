import sys
input = sys.stdin.readline
print = sys.stdout.write

def get_distance(x1,y1,x2,y2):
    return ((x2-x1)**2 + (y2-y1)**2)**0.5

test_case = int(input().rstrip("\n"))
for i in range(test_case):
    x1,y1,r1,x2,y2,r2 = map(int,input().split())
    distance = get_distance(x1,y1,x2,y2)
    if(r1+r2<distance):
        print("0\n")
    elif(r1+r2>distance):
        if(abs(distance)+r1 < r2 or abs(distance)+r2 < r1):
            print("0\n")
        elif(abs(distance)+r1 == r2 or abs(distance)+r2 == r1):
            if(x1==x2 and y1==y2):
                print("-1\n")
            else:
                print("1\n")
        else:
            print("2\n")
    else:
        if(x1==x2 and y1==y2):
            print("-1\n")
        else:
            print("1\n")


