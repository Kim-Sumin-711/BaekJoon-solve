import sys
input = sys.stdin.readline
print = sys.stdout.write

a = input().rstrip("\n")
b = input().rstrip("\n")
c = input().rstrip("\n")
d = input().rstrip("\n")

trigger1 = (a=='8' or a=='9')
trigger2 = (d=='8' or d=='9')
trigger3 = b==c

if(trigger1 and trigger2 and trigger3): print("ignore")
else: print("answer")