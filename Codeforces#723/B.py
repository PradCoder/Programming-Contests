def solve1(dp,lst,n):
    dp[0] = 1
    for j in lst:
        for i in range(1,n+1):
            if(i - j < 0):
                dp[i] += 0
            else:
                dp[i] += dp[i-j]
    return dp

def solve(v):
    dp, lst = [],[]
    n = max(v);
    lst.append(11)
    dp = [0]*(n+1)
    while(n>lst[-1]):
        i = lst[-1]*10+1
        lst.append(i)
    dp = solve1(dp,lst,n)
    for j in v:
        print(f"{'YES' if dp[j] > 0 else 'NO'}")

def main():
    t = int(input())
    v = []
    for _ in range(t):
        n = int(input());
        v.append(n)
    solve(v)
        

if __name__ == "__main__":
    main()
