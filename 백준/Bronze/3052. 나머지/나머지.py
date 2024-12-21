import sys
input = sys.stdin.readline
print = sys.stdout.write

rest_set = set()

for i in range(10):
    tmp = int(input().rstrip("\n"))%42
    rest_set.add(tmp)
print(f"{len(rest_set)}")
