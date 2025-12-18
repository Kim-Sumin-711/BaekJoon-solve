a = int(input())
b = int(input())
c = int(input())
num = a*b*c

num_dict = {0 : 0,
            1 : 0,
            2 : 0,
            3 : 0,
            4 : 0,
            5 : 0,
            6 : 0,
            7 : 0,
            8 : 0,
            9 : 0}
num_text = str(num)
for ch in num_text:
    num_dict[int(ch)]+=1

for i in range(0,10):
    print(num_dict[i])