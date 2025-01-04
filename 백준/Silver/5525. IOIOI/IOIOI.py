import sys
read = sys.stdin.readline
write = sys.stdout.write

p_len = int(read().rstrip("\n"))
str_len = int(read().rstrip("\n"))
string = read().rstrip("\n")
index, tmp_len, remain_len,finding = 0,0,0,0
while(index < str_len-1):
    index = string.find('I',index)
    if(index ==-1 or index >= str_len-2):
        break
    tmp_len += remain_len
    while(tmp_len < p_len):
        if(index >= str_len-2):
            break
        if(string[index+1] == 'O' and string[index+2] == 'I'):
            tmp_len+=1
            index+=2
            if(tmp_len == p_len):
                finding+=1
                remain_len = tmp_len-1
                tmp_len = 0
                break
        else:
            tmp_len, remain_len = 0 , 0
            index += 1
            break
write(f"{finding}")