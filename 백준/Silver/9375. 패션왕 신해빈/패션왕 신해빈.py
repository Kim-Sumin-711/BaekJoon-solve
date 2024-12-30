import sys
read = sys.stdin.readline
write = sys.stdout.write

def set_cloth_dict(dict):
    cloth_cnt = int(read().rstrip("\n"))
    for i in range(cloth_cnt):
        cloth_name, cloth_sub = read().rstrip("\n").split()
        if(cloth_sub in dict):
            dict[cloth_sub]+=1
        else:
            dict[cloth_sub] = 1

def get_cloth_combi_cnt(cloth_cnt_list):
    res=1
    for cnt in cloth_cnt_list:
        res*=(cnt+1)
    return res-1

test_case = int(read().rstrip("\n"))
for _ in range(test_case):
    cloth_dict = {}
    set_cloth_dict(cloth_dict)
    cloth_cnt_by_sub_list = list(cloth_dict.values())
    write(f"{get_cloth_combi_cnt(cloth_cnt_by_sub_list)}\n")