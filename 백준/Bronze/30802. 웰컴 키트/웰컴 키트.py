import sys
input = sys.stdin.readline
print = sys.stdout.write

def cloth_pack_cnt(req,t):
    if(req%t != 0):
        return req//t+1
    else:
        return req//t

total = int(input().rstrip("\n"))
cloth_list = list(map(int, input().rstrip("\n").split()))
t,p = map(int, input().rstrip("\n").split())
tmp_sum=0
for elem in cloth_list:
    tmp_sum += cloth_pack_cnt(elem,t)

print(f"{tmp_sum}\n")
print(f"{total//p} {total%p}")