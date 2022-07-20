def solve(n, ls):
    i = 0
    while i < n:
        if not (ls[i%n] == ls[(i+1)%n]):
            if(ls[(i+1)%n] == ls[(i+2)%n]):
                return i+1
            else:
                return i+2
        i+=1

def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        ls = list(map(int,input().split()))
        print(solve(n,ls))
    
if __name__ == "__main__":
    main()