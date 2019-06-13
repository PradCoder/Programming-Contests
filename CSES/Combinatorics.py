memo = []
def per1(n):
    if(n<len(memo)):
        return memo[n]
    else:
        su = 0
        if(n==0):
            su = 1
        else:
            for i in range(1,n+1):
                su+=per1(n-i)
        memo.append(su)
        return su
def per2(n):
    ans = 1
    if(n-1>=0): 
        ans = 2**(n-1)
    return ans
def main():
    string1 = (str)(per1(996))
    string2 = (str)(per2(10000))
    print(string1,len(string1))
    print(string2,len(string2))
    #maximum recursion until 2959 using memoization the size of the output is 891 numbers long
    #this is impossible to do in c/c++ and Java without
    #without memoization bigger numbers (>=100) are not possible in less than 1 second

if __name__ == "__main__":
    main()