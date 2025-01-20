import sys
input = sys.stdin.readline
write = sys.stdout.write

name_len1, name_len2 = map(int,input().rstrip("\n").split())
name1, name2 = input().rstrip("\n").split()
alpha_num_dict= {'A':3,'B':2,'C':1,'D':2,'E':4,'F':3,'G':1,'H':3,'I':1,'J':1,'K':3,"L":1,
'M':3,"N":2,"O":1,"P":2,"Q":2,"R":2,'S':1,"T":2,"U":1,"V":1,"W":1,"X":2,"Y":2,"Z":1}

extended_name = ""
for i in range(min(name_len1,name_len2)):
    extended_name+=name1[i]+name2[i]
if(name_len1 > name_len2):
    extended_name+=name1[name_len2:name_len1]
else:
    extended_name+=name2[name_len1:name_len2]

name_to_int = []
for ch in extended_name:
    name_to_int.append(alpha_num_dict[ch])

max_index = name_len1+name_len2
while(max_index !=2):
    for i in range(max_index-1):
        name_to_int[i]+=name_to_int[i+1]
        name_to_int[i]%=10
    max_index-=1
if(name_to_int[0]!=0):
    write(f"{name_to_int[0]}{name_to_int[1]}%")
else:
    write(f"{name_to_int[1]}%")
