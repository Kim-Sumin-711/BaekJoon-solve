import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    strs = list(map(str, input().rstrip("\n").split()))
    for string in strs:
        val = 0
        for char in string:
            val += ord(char)-97
        if(val%27 == 26):
            print(" ")
        else:
            print(f"{chr(val%27+97)}")
    print("\n")

