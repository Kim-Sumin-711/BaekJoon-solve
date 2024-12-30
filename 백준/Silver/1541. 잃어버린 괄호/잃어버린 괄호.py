import sys
input = sys.stdin.readline
write = sys.stdout.write

input_string = input().rstrip("\n")

found_minus = False
sum  = 0
tmp = ""
for char in input_string:
    if(char != "+" and char != "-"):
        tmp+=char
    elif(char == "-"):
        if(found_minus):
            sum-=int(tmp)
            tmp = ""
        else:
            found_minus = True
            sum += int(tmp)
            tmp = ""
    else:
        if(found_minus):
            sum -= int(tmp)
            tmp = ""
        else:
            sum+=int(tmp)
            tmp = ""
if(found_minus):
    sum-=int(tmp)
else:
    sum+=int(tmp)
write(f"{sum}")