import sys
from collections import deque
read = sys.stdin.readline
write = sys.stdout.write

def set_spot_dict(spot_dict, spot):
    for s1 in range(spot):
        tmp_list = list(map(int,read().rstrip("\n").split()))
        for s2 in range(spot):
            if(tmp_list[s2] == 0):
                continue
            if(s1+1 in spot_dict):
                spot_dict[s1+1].append(s2+1)
            else:
                spot_dict[s1+1] = [s2+1]

def get_connection_list(spot_dict,spot):
    connection_list = [0 for _ in range(spot)]
    for target in range(1,spot+1):
        connection_list[target-1] = BFS_from_target_spot(spot_dict,target,spot)
    return connection_list
    
def BFS_from_target_spot(spot_dict,target,spot_cnt):
    visit_history = [0 for _ in range(spot_cnt+1)]
    spot_deque = deque()
    spot_deque.append(target)
    res_list = [0 for _ in range(spot_cnt)]
    while(len(spot_deque) != 0):
        now = spot_deque.popleft()

        if(not now in spot_dict):
            continue
        else:
            for elem in spot_dict[now]:
                if(visit_history[elem] == 0):
                    res_list[elem-1] = 1
                    spot_deque.append(elem)
                    visit_history[elem] = 1 
    return res_list

def print_2D_list(alist):
    for elem_list in alist:
        for elem in elem_list:
            write(f"{elem} ")
        write("\n")

def sol(spot,spot_dict):
    print_2D_list(get_connection_list(spot_dict,spot))

spot = int(read().rstrip("\n"))
spot_dict = {}
set_spot_dict(spot_dict,spot)
sol(spot,spot_dict)