import sys
input = sys.stdin.readline
write = sys.stdout.write

have = int(input().rstrip("\n"))
have_dict = {}
for elem in map(int,input().rstrip("\n").split()):
    if(elem in have_dict):
        have_dict[elem]+=1
    else:
        have_dict[elem] = 1
find = int(input().rstrip("\n"))
find_iter = map(int,input().rstrip("\n").split())

for elem in find_iter:
    if(elem in have_dict):
        write(f"{have_dict[elem]} ")
    else:
        write("0 ")