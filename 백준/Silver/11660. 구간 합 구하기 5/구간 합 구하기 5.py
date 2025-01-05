import sys
input = sys.stdin.readline

table_size, calc_cnt = map(int,input().split())
accumlative_num_table = [0 for _ in range(table_size)]


for i in range(table_size):
    tmp_accumlative_sum = 0
    tmp_list = [0 for _ in range(table_size)]
    tmp_index = 0
    for num in list(map(int,input().split())):
        tmp_list[tmp_index] += num+tmp_accumlative_sum
        tmp_accumlative_sum = tmp_list[tmp_index]
        tmp_index+=1
    accumlative_num_table[i] = tmp_list.copy()

for _ in range(calc_cnt):
    res = 0
    x1, y1, x2, y2 = map(int,input().split())
    x1-=1
    x2-=1
    y1-=1
    y2-=1
    for row in range(x1, x2+1):
        if(y1 == 0):
            res += accumlative_num_table[row][y2]
        else:
            res += accumlative_num_table[row][y2]-accumlative_num_table[row][y1-1]
    sys.stdout.write(f"{res}\n")