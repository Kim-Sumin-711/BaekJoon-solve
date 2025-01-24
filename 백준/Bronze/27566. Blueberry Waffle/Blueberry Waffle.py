import sys
input = sys.stdin.readline
write = sys.stdout.write

period, cooking_time = map(int,input().rstrip("\n").split())
total_rotate_angle = cooking_time / period * 180
total_rotate_angle %= 360
if(total_rotate_angle < 90):
    write("up")
elif(total_rotate_angle<270):
    write("down")
else:
    write("up")