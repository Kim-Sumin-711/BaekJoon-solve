import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input().rstrip("\n"))
text = input().rstrip("\n")
alpha_map = {'a':0,
             'b':0,
             'c':0,
             'd':0,
             'e':0,
             'f':0,
             'g':0,
             'h':0,
             'i':0,
             'j':0,
             'k':0,
             'l':0,
             'm':0,
             'n':0,
             'o':0,
             'p':0,
             'q':0,
             'r':0,
             's':0,
             't':0,
             'u':0,
             'v':0,
             'w':0,
             'x':0,
             'y':0,
             'z':0
             }
for each_char in text:
    if(each_char in alpha_map.keys()):
        alpha_map[each_char]+=1

ans = 0
for key in alpha_map.keys():
    if(alpha_map[key] > ans):
        ans = alpha_map[key]

print(f"{ans}")
