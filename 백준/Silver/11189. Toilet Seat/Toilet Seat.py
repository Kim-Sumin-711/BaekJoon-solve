import sys
input = sys.stdin.readline
print = sys.stdout.write

string = input().rstrip("\n")
toilet = string[0]
people = list(map(str, string[1:]))

cnt = 0
for person in people:
    if(toilet=="D"):
        toilet="U"
        cnt+=1
    else:
        if(person=="D"):
            cnt+=2
print(f"{cnt}\n")
toilet = string[0]

cnt=0
for person in people:
    if(toilet=="D"):
        if(person=="U"):
            cnt+=2
    else:
        if(person=="U"):
            cnt+=1
        else:
            cnt+=1
            toilet = "D"
print(f"{cnt}\n")
toilet = string[0]

cnt=0
for person in people:
    if(toilet!=person):
        cnt+=1
        toilet = person
print(f"{cnt}\n")