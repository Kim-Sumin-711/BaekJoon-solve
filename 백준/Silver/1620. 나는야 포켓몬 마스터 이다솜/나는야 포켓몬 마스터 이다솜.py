import sys
input = sys.stdin.readline
print = sys.stdout.write

poke, problem = map(int,input().rstrip("\n").split())
poke_dict = {}

for i in range(poke):
    pokemon = input().rstrip("\n")
    poke_dict[pokemon] = i+1
    poke_dict[i+1] = pokemon
for _ in range(problem):
    target = input().rstrip("\n")
    if(target.isdigit()):
        print(f"{poke_dict[int(target)]}\n")
    else:
        print(f"{poke_dict[target]}\n")
