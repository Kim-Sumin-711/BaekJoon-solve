import sys
input = sys.stdin.readline
print= sys.stdout.write

want = int(input().rstrip("\n"))
if(want == 1):
    print("666")
else:
    tmp = 1666
    while(want-1 > 0):
        if("666" in f"{tmp}"):
            want-=1
        tmp+=1
    print(f"{tmp-1}")