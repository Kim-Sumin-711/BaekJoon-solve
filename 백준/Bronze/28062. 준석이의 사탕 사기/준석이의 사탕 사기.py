import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input().rstrip("\n"))
if(N==1):
    num = int(input().rstrip("\n"))
    if(num%2==0):
        print(f"{num}")
    else:
        print(f"{0}")
else:
    num_array = list(map(int,input().rstrip("\n").split()))
    min_odd = 1001
    odd_cnt = 0
    sum = 0
    for num in num_array:
        if(num%2==0):
            sum += num
        else:
            if(num < min_odd):
                min_odd = num
            sum += num
            odd_cnt+=1

    if(odd_cnt%2==0):
        print(f"{sum}")        
    else:
        print(f"{sum-min_odd}")
        
    
