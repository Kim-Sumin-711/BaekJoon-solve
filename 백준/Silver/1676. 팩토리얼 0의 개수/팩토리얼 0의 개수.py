import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input().rstrip("\n"))
if(n<5):
    print("0")
elif(n<10):
    print("1")
else:
    fac = 1
    for i in range(2,n+1):
        fac*=i
    factxt = str(fac)
    zero_cnt = 0
    for i in range(1,len(factxt)):
        if(factxt[-i] == '0'):
            zero_cnt+=1
        else:
            break
    print(f"{zero_cnt}")