import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write


card_deck = deque([i+1 for i in range(int(input().rstrip("\n")))])

while(len(card_deck) > 2) :
    card_deck.popleft()
    tmp = card_deck.popleft()
    card_deck.append(tmp)
if(len(card_deck) == 2):
    print(f"{card_deck[1]}")
elif(len(card_deck) == 1):
    print(f"{card_deck[0]}")
