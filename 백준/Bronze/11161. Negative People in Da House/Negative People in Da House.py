import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    info_cnt =int(input().rstrip("\n"))
    mini = 0
    add = 0
    while(info_cnt):
        info_cnt-=1
        enter, out = map(int,input().rstrip("\n").split())
        if(out < enter):
            add+=enter-out
        else:
            if(add > out-enter):
                add-=out-enter
            else:
                mini+= out-enter-add
                add=0
            
    print(f"{mini}\n")
