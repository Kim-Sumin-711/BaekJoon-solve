import sys
input = sys.stdin.readline
print = sys.stdout.write

def find_rule(alist):
    asc = False
    desc = False

    for i in range(7):
        if(alist[i] > alist[i+1]):
            desc = True
        else:
            asc = True

    if(asc and desc):
        print("mixed")
    elif(asc):
        print("ascending")
    elif(desc):
        print("descending")
    else:
        print("something is wrong")

num_list = list(map(int, input().rstrip("\n").split()))
find_rule(num_list)


