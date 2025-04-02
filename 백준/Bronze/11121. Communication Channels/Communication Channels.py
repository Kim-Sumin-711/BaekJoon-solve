import sys
input = sys.stdin.readline
print = sys.stdout.write

test_case = int(input().rstrip("\n"))
while(test_case):
    test_case-=1
    send,receive = input().rstrip("\n").split()
    if(send == receive):
        print("OK\n")
    else:
        print("ERROR\n")