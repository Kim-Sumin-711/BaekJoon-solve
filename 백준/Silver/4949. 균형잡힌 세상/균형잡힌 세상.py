import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write

def sol(string):
    gwalho_deque = deque([])
    for char in string:
        if(char == "(" or char == "["):
            gwalho_deque.append(char)
        elif(char == ")"):
            if(len(gwalho_deque) == 0):
                return False
            if(gwalho_deque.pop() != "("):
                return False
        elif (char == "]"):
            if(len(gwalho_deque) == 0):
                return False
            if(gwalho_deque.pop() != "["):
                return False
    if(len(gwalho_deque) != 0):
        return False
    else:
        return True


string = input().rstrip("\n")
while(string != "."):
    if(sol(string)):
        print("yes\n")
    else:
        print("no\n")
    string = input().rstrip("\n")
