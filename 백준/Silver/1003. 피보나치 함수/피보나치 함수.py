import sys
input = sys.stdin.readline

test_case = int(input().rstrip("\n"))
dp = [[1,0]]
dp_calced = 0
for i in range(test_case):
    num = int(input().rstrip("\n"))
    while(dp_calced < num):
        dp.append([dp[dp_calced][1], dp[dp_calced][0]+dp[dp_calced][1]])
        dp_calced+=1
    sys.stdout.write(f"{dp[num][0]} {dp[num][1]}\n")
