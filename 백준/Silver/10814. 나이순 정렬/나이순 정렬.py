import sys
input = sys.stdin.readline
print = sys.stdout.write

people = int(input().rstrip("\n"))
people_list = []
for num in range(people):
    people_list.append(input().rstrip("\n").split())
    people_list[num].append(num)
people_list.sort(key=lambda x: (int(x[0]),x[2]))
for person in people_list:
    print(f"{person[0]} {person[1]}\n")