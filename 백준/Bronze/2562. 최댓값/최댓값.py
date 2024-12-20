import sys
input = sys.stdin.readline

max = 0
index = 0
for i in range(9):
    tmp = int(input().rstrip("\n"))
    if(tmp > max):
        max = tmp
        index = i
sys.stdout.write(f"{max}\n{index+1}")