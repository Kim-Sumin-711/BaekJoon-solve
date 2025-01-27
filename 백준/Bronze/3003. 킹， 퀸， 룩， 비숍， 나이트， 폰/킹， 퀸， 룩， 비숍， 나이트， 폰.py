import sys
input = sys.stdin.readline
write = sys.stdout.write

king, queen, rook, bishop, knight, phone = map(int,input().rstrip("\n").split())
write(f"{1 - king} {1- queen} {2 - rook} {2 - bishop} {2 - knight} {8 - phone}")