import sys
input = sys.stdin.readline
print = sys.stdout.write

target = int(input().rstrip("\n"))
string = str(bin(target))

string = string[-1:1:-1]

two=2**(len(string)-1)
result =0
for char in string:
    result+=int(char)*two
    two/=2
print(f"{int(result)}")