import sys
input = sys.stdin.readline
print = sys.stdout.write

a_dict = {}
a=int(input().rstrip("\n"))
b=int(input().rstrip("\n"))
c=int(input().rstrip("\n"))
res = str(a*b*c)
for char in res:
    if(int(char) in a_dict):
        a_dict[int(char)] += 1
    else:
        a_dict[int(char)] = 1

for num in range(10):
    if(num in a_dict):
        print(f"{a_dict[num]}\n")
    else:
        print("0\n")
