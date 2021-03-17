def solve(lst):
    s = 0
    j = 0
    for i in range(len(lst)):
            s += lst[i]
            j += i
            if(s < j):
                return "NO"
    return "YES"

def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        lst = list(map(int,input().split()))
        print(solve(lst))

if __name__ == "__main__":
    main()
