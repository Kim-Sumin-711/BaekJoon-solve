import sys
input = sys.stdin.readline
print = sys.stdout.write

start = int(input().rstrip("\n"))
end = int(input().rstrip("\n"))
now = start
while(now <= end):
    print(f"All positions change in year {now}\n")
    now+=60