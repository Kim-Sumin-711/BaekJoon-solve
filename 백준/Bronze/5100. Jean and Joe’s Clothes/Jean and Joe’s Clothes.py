import sys
input = sys.stdin.readline
write = sys.stdout.write



while True:
    joe,jean,james,jane,nono = 0,0,0,0,0
    cloth_cnt = int(input().rstrip("\n"))
    if(cloth_cnt  == 0):
        break
    for _ in range(cloth_cnt):
        cloth = input().rstrip("\n")
        if(cloth == 'M' or cloth == 'L'):
            joe +=1
        elif(cloth == 'S'):
            james += 1
        elif(cloth.isdigit()):
            if(int(cloth) >= 12):
                jean+=1
            else:
                jane +=1
        else:
            nono +=1
    write(f"{joe} {jean} {jane} {james} {nono}\n")
