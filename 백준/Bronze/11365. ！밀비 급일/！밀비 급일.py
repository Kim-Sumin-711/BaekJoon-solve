import sys
read = sys.stdin.readline
write = sys.stdout.write

while True:
    string = read().rstrip("\n")
    if(string == "END"):
        break
    write(f"{string[-1:0:-1]}")
    write(f"{string[0]}\n")