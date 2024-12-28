import sys
input = sys.stdin.readline
write = sys.stdout.write

test = int(input().rstrip("\n"))
setA,setB,setC = 0,0,0

for _ in range(test):
    tmpA,tmpB,tmpC = map(int,input().rstrip("\n").split())
    setA += tmpA
    setB += tmpB
    setC += tmpC
    if(setA < 30 or setB < 30 or setC < 30):
        write("NO\n")
    else:
        distri = min(setA,setB,setC)
        write(f"{distri}\n")
        setA -= distri
        setB -= distri
        setC -= distri