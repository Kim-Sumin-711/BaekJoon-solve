import sys
read = sys.stdin.readline
write = sys.stdout.write

total_site, find_site = map(int, read().rstrip("\n").split())

memojang = {}
target_list = []
for _ in range(total_site):
    site,pw = read().rstrip("\n").split()
    memojang[site] = pw

for _ in range(find_site):
    tmp = read().rstrip("\n")
    target_list.append(tmp)

for target in target_list:
    write(f"{memojang[target]}\n")