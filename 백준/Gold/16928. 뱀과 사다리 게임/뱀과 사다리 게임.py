import sys
from collections import deque
read = sys.stdin.readline
write = sys.stdout.write

def set_dict(di,size):
    for _ in range(size):
        start, end = map(int,read().rstrip("\n").split())
        di[start] = end

#BFS
def search_min_cnt(sadaris,snakes):
    now = 1
    possible_route_deque = deque()
    possible_route_deque.append(now)
    dp = [100 for _ in range(101)]
    dp[1] = 0
    while(len(possible_route_deque) != 0):
        now = possible_route_deque.popleft()
        if(now in sadaris):
            if(dp[sadaris[now]] > dp[now]):
                dp[sadaris[now]] = dp[now]
                now = sadaris[now]
            else:
                continue
        elif(now in snakes):
            if(dp[snakes[now]] > dp[now]):
                dp[snakes[now]] = dp[now]
                now = snakes[now]
            else:
                continue
        for move in range(now+1,now+7):
            if(move > 100):
                break
            if(dp[move] > dp[now]+1):
                dp[move] = dp[now]+1
                if(move in snakes):
                    if(dp[snakes[move]] > dp[now]+1):
                        dp[snakes[move]] = dp[now]+1
                        possible_route_deque.append(snakes[move])
                elif(move in sadaris):
                    if(dp[sadaris[move]] > dp[now]+1):
                        dp[sadaris[move]] = dp[now]+1
                        possible_route_deque.append(sadaris[move])
                else:
                    possible_route_deque.append(move)
    return dp[100]

sadari, snake = map(int, read().rstrip("\n").split())
sadari_dict, snake_dict = {}, {}
set_dict(sadari_dict,sadari)
set_dict(snake_dict,snake)
min_dice_cnt = search_min_cnt(sadari_dict, snake_dict)
write(f"{min_dice_cnt}")