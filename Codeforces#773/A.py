def solve(ls, n):
    for i in range(2*n):

def main():
    t = int(input())
    for i in range(t):
        n = int(input());
        ls = map(int,input().split());
        print(f"{str(solve(ls,n))[1:-1]}");
        

if __name__ == "__main__":
    main()
