n = int(input())
while n!=-1 :
    fibo1 = 1
    fibo2 = 1
    temp = 1
    for i in range(2,n):
        temp = fibo2
        fibo2+=fibo1
        fibo1 = temp
    print(f"Hour {n}: {fibo2} cow(s) affected")
    n = int(input())
