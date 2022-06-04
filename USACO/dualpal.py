'''
ID: 2010pes1
TASK: dualpal
LANG: PYTHON3
'''
def convert(n,i,nums):
    lst = []
    st = ''
    while i>0:
        lst.append(nums[i%n])
        i = (i - (i%n))/n
    for i in range(len(lst)):
        st += lst[len(lst)-1-i]
    return st

# filter solutions that are already palindromic in one base (ex: base 2)
# with every other base to find a solution (ex: bases, 3 or 4 or 5 or 6.. or 10)
# in case there are lesser solutions than the current one 
# store the first n numbers greater than s, that satisfy the above condition in memory
def solve(n,s,nums):
    f = open("dualpal.out","w")
    i = 0
    for k in range (2,10+1):
        val = s+1
        while i < n:
            lst = convert(k,val,nums)
            p = True
            for j in range(len(lst)//2):
                if lst[j] != lst[len(lst)-1-j]:
                    p = False
                    break
            if p and i<n:
                f.write(f"{val}\n") 
                i+=1
            val+=1
    f.close()

def main():
    f = open("dualpal.in", "r")
    n, s = map(int,f.read().strip().split(" "))
    nums = {}
    for i in range(0,9+1):
        nums[i] = str(i)
    solve(n,s,nums)
    f.close()

if __name__ == "__main__":
    main()
