import sys
from collections import deque
input = sys.stdin.readline
write = sys.stdout.write


test_case = int(input().rstrip("\n"))
for _ in range(test_case):
    gwalho_deque = deque([])
    string = input().rstrip("\n")
    for char in string:
        if(char == "("):
            gwalho_deque.append(char)
        else:
            if(len(gwalho_deque) == 0):
                write("NO\n")
                break
            gwalho_deque.pop()
    else:
        if(len(gwalho_deque) !=0 ):
            write("NO\n")
        else:
            write("YES\n")