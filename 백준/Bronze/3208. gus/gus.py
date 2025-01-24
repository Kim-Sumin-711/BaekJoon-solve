import sys
input = sys.stdin.readline
write = sys.stdout.write

row, col = map(int,input().rstrip("\n").split())
turn_cnt = 0
while(row != 0 and col!=0):
    row-=1
    turn_cnt+=1
    if(row == 0):
        break
    else:
        col-=1
        turn_cnt+=1
write(f"{turn_cnt-1}")