N=int(input())
ing_list = input().split()
used_ing_list = input().split()

for ing in ing_list:
    found = False
    for used_ing in used_ing_list:
        if(ing == used_ing):
            found=True
            break
    if(found == False):
        print(ing)
        break