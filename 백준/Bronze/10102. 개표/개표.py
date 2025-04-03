import sys
input = sys.stdin.readline
print = sys.stdout.write

int(input().rstrip("\n"))

string = input().rstrip("\n")
a,b=0,0
for char in string:
    if(char=="A"):
        a+=1
    else:
        b+=1
if(a>b):
    print("A")
elif(a<b):
    print("B")
else:
    print("Tie")