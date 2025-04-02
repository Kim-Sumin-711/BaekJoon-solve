import sys
input = sys.stdin.readline
print = sys.stdout.write

test_case = int(input().rstrip("\n"))
while(test_case) :
    test_case-=1
    weight_cnt  = int(input().rstrip("\n"))
    num_list = list(map(int,input().rstrip("\n").split()))
    total_F = sum(num_list)
    if(total_F>0):
        print("Right\n")
    elif(total_F<0):
        print("Left\n")
    else:
        print("Equilibrium\n")