import sys
read = sys.stdin.readline
write = sys.stdout.write

def set_dict(dict, elem_cnt):
    for _ in range(elem_cnt):
        tmp = read().rstrip("\n")
        dict[tmp] = 1

def get_cnt_of_noseen_noheard_people(noseens, noheards):
    cnt = 0
    people_list = []
    for elem in noseens:
        if(elem in noheards):
            cnt +=1
            people_list.append(elem)
    people_list.sort()
    return cnt, people_list

noseen, noheard = map(int,read().rstrip("\n").split())
noseen_dict, noheard_dict = {},{}

set_dict(noseen_dict,noseen)
set_dict(noheard_dict,noheard)

tmp = get_cnt_of_noseen_noheard_people(noseen_dict,noheard_dict)
write(f"{tmp[0]}\n")
for elem in tmp[1]:
    write(f"{elem}\n")