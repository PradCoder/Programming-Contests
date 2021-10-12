import math

def solve(n):
    pOfTwo = 2
    while(pOfTwo <= n):
        if(math.sqrt(n/pOfTwo).is_integer()):
            return True    
        pOfTwo= pOfTwo << 1
    return False

def main():
    nt = int(input())
    for i in range(nt):
        st = solve(int(input()))
        if st == True:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()
