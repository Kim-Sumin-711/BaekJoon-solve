import sys
from collections import deque
read = sys.stdin.readline
write = sys.stdout.write

def min_val_in_list(alist):
    min_val = 2**31-1
    min_list = []
    for i in range(1,len(alist)):
        if(min_val > alist[i]):
            min_val = alist[i]
            min_list.clear()
            min_list.append(i)
        elif(min_val == alist[i]):
            min_list.append(i)
    return min_list[0]

def add_connection(connection_list, user, connection_dict,visit):
    for person in connection_dict[user]:
        if(visit[person]==0):
            connection_list.append(person)
            visit[person] = 1


#return connections cnt a target has
def find_connection_cnt(people_dict,user_cnt,target):
    connection_cnt = 1
    visit = [0 for _ in range(user_cnt+1)]
    connection_deque = deque()
    tmp_connection_list = []
    connection_deque.append(target)
    visit[target] = 1
    add_connection(tmp_connection_list,target,people_dict,visit)
    for elem in tmp_connection_list:
        connection_deque.append(elem)
    tmp_connection_list.clear()
    while(len(connection_deque) != 0):
        while(len(connection_deque) != 0):
            user = connection_deque.popleft()
            visit[user] = connection_cnt
            add_connection(tmp_connection_list,user,people_dict,visit)
        connection_cnt+=1
        for elem in tmp_connection_list:
            connection_deque.append(elem)
        tmp_connection_list.clear()
    return sum(visit)-1



def set_dict(people,connection):
    for _ in range(connection):
        u,c = map(int,read().rstrip("\n").split())
        if(u in people):
            people[u].add(c)
        else:
            people[u] = set([c])
        if(c in people):
            people[c].add(u)
        else:
            people[c] = set([u])

user, connection = map(int,read().rstrip("\n").split())
people_dict = {}
set_dict(people_dict,connection)
res_list = [0 for _ in range(user+1)]
for tar in range(1,user+1):
    res_list[tar] = find_connection_cnt(people_dict,user,tar)
write(f"{min_val_in_list(res_list)}")
