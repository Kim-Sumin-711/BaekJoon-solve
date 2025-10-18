import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input().rstrip("\n"))
ans = 0
each_elem = 1
for i in range(N):
    text = input().rstrip("\n")
    num = int(text[0:-1])
    pot = int(text[-1])
    for j in range(pot):
        each_elem*=num
    ans+=each_elem
    each_elem=1
print(f"{ans}")
