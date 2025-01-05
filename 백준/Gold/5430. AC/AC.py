import sys
from collections import deque
read = sys.stdin.readline
write = sys.stdout.write

def string_to_deque(tmp_str,num_deque):
    tmp_str = tmp_str.lstrip('[').rstrip(']')
    if(len(tmp_str)!=0):
        for elem in tmp_str.split(','):
            num_deque.append(elem)




#if something wrong, return 1, reverse. if not return 0, reverse.
def handle_case(operation, num_deque,reverse=False):
    for oper in operation:
        if(oper == 'D'):
            if(len(num_deque) == 0):
                return 1,reverse
            else:
                if(reverse):
                    num_deque.pop()
                else:
                    num_deque.popleft()
        else:
            reverse = (not reverse)
    return 0,reverse

def print_deque(de,reverse):
    if(len(de) == 0):
        write("[]\n")
    else:
        if(not reverse):
            write(f"[{de.popleft()}")
            while(len(de) != 0):
                write(f",{de.popleft()}")
        else:
            write(f"[{de.pop()}")
            while(len(de) != 0):
                write(f",{de.pop()}")
        write("]\n")



test_case = int(read().rstrip("\n"))
for _ in range(test_case):
    operation = read().rstrip("\n")
    size = int(read().rstrip("\n"))
    tmp_str = read().rstrip("\n")
    num_deque = deque()
    string_to_deque(tmp_str,num_deque)
    res = handle_case(operation,num_deque)
    if(res[0] == 1):
        write("error\n")
    else:
        print_deque(num_deque,res[1])
