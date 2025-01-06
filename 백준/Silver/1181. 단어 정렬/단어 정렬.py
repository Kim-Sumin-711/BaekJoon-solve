import sys
fastinput, fastprint = sys.stdin.readline, sys.stdout.write

textList = []
text_dict = {} # {len(string) : [strings]}

for _ in range(int(fastinput())):
    text = fastinput()
    if(len(text) in text_dict):
        text_dict[len(text)] += [text]
    else:
        text_dict[len(text)] = [text]

for Txtlen in range(53):
    if(Txtlen in text_dict):
        text_dict[Txtlen] = list(set(text_dict[Txtlen]))
        for string in sorted(text_dict[Txtlen]):
            textList.append(string)

for i in textList:
    fastprint(i)