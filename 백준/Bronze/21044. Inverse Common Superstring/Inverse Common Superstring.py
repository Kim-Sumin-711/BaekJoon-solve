import sys
input = sys.stdin.readline
print = sys.stdout.write

string = input().rstrip("\n")
size = 1
only_a = True

for char in string:
    if(char!="a"):
        only_a = False
        break


while not only_a:
    a_found = False
    for i in range(len(string)-size+1):
        char = string[i:i+size]
        if(char == "a"*size):
            a_found = True
    if(not a_found):
        print("a"*size)
        break
    size+=1

if(only_a):
    print(string+"a")
