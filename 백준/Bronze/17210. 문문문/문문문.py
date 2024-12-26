import sys
input = sys.stdin.readline
print = sys.stdout.write

door = int(input().rstrip("\n"))
howOpen = int(input().rstrip("\n"))
if(door >= 6):
     print("Love is open door")
else:
     for i in range(door-1):
          howOpen = not howOpen
          print(f"{int(howOpen)}\n")