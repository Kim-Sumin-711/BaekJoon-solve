import sys
input = sys.stdin.readline
write = sys.stdout.write

def get_approved_ice_combi_cnt(icecreams,awful_dict):
    approved_cnt = 0
    for start in range(1,icecreams-1):
        for middle in range(start+1, icecreams):
            if(is_not_approved_combi(start,middle,awful_dict)):
                continue
            for end in range(middle+1,icecreams+1):
                if(is_not_approved_combi(middle,end,awful_dict)):
                    continue
                if(is_not_approved_combi(start,end,awful_dict)):
                    continue
                approved_cnt +=1
    return approved_cnt

def is_not_approved_combi(a,b,awful_dict):
    if(a in awful_dict):
        if(b in awful_dict[a]):
            return True
        else:
            return False
    else:
        return False



icecreams, awful = map(int, input().rstrip("\n").split())

awful_dict = {}

for _ in range(awful):
    no1, no2 = map(int, input().rstrip("\n").split())
    if(no1 in awful_dict):
        awful_dict[no1].append(no2)
    else:
        awful_dict[no1] = [no2]

    if(no2 in awful_dict):
        awful_dict[no2].append(no1)
    else:
        awful_dict[no2] = [no1]
write(f"{get_approved_ice_combi_cnt(icecreams,awful_dict)}")
