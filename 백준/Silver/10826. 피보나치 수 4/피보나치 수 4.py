import sys
input = sys.stdin.readline
print = sys.stdout.write

def get_Fibonacci_number(N):
    if (N == 0): return 0
    if (N == 1): return 1
    if (N == 2): return 1
    if (N == 3): return 2

    is_odd = N%2

    if(is_odd):
        simplized_N = (N-1)/2
        temp = get_Fibonacci_number(simplized_N+1)
        temp2 = get_Fibonacci_number(simplized_N)
        return temp*temp + temp2*temp2
    else:
        simplized_N = N/2
        temp = get_Fibonacci_number(simplized_N-1)
        temp2 = get_Fibonacci_number(simplized_N)
        return temp2*temp2 + 2*temp*temp2
    
N = int(input().rstrip("\n"))
Fibonacci_number_of_N = get_Fibonacci_number(N)
print(str(Fibonacci_number_of_N))