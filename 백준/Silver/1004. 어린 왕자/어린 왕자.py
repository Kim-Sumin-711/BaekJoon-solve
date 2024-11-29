import sys
input = sys.stdin.readline

#p1 : (x,y), p2 : (x,y), circle_info : (x,y,r)
def get_enter_exit_cnt(p1,p2,circle_info):
    distance1 = ((circle_info[0]-p1[0])**2 + (circle_info[1] - p1[1])**2)**0.5
    distance2 =  ((circle_info[0]-p2[0])**2 + (circle_info[1] - p2[1])**2)**0.5
    #let calc == r is impossible.
    if(distance1 < circle_info[2] and distance2 < circle_info[2]):
        return 0
    elif(distance1 < circle_info[2] or distance2 < circle_info[2]):
        return 1
    else:
        return 0


test = int(input().rstrip("\n"))
for _ in range(test):
    startX, startY, goalX, goalY = map(int,input().split())
    system = int(input().rstrip("\n"))
    enter_exit_cnt = 0
    for i in range(system):
        centerX,centerY,radius = map(int, input().split())
        enter_exit_cnt += get_enter_exit_cnt((startX, startY), (goalX,goalY), (centerX, centerY, radius))
    sys.stdout.write(f"{enter_exit_cnt}\n")

