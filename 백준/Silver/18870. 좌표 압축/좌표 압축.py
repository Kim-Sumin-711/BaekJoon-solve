import sys
input = sys.stdin.readline
write = sys.stdout.write

def print_list(li):
    for elem in li :
        write(f"{elem} ")

num_cnt = int(input().rstrip("\n"))
num_list = list(map(int, input().rstrip("\n").split()))
num_dict = {}
for i in range(num_cnt) :
    if(num_list[i] in num_dict):
        num_dict[num_list[i]].append(i)
    else:
        num_dict[num_list[i]] = [i]
num_list = list(set(num_list))
num_list.sort()
result_list = [0 for _ in range(num_cnt)]
res = 0
for num in num_list:
    for index in num_dict[num]:
        result_list[index] = res
    res+=1
print_list(result_list)

