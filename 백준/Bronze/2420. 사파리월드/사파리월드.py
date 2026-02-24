a,b=map(int,input().split())
if b>a:
    temp = b
    b = a
    a = temp
print(a-b)