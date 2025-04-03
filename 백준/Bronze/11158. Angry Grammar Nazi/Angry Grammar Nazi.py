import sys
input = sys.stdin.readline
print = sys.stdout.write

test = int(input().rstrip("\n"))
while test:
    test-=1
    cnt = 0
    string = list(map(str,input().rstrip("\n").split()))
    would_should_found = False
    for strs in string:
        if(would_should_found):
            if(strs == "of"):
                cnt+=1
            would_should_found=False
        if(strs == "u" or strs=="ur"):
            cnt+=1
        elif(strs =="would" or strs == "should"):
            would_should_found=True
        elif(strs.find("lol")!=-1):
            cnt+=1
    print(f"{cnt*10}\n")
