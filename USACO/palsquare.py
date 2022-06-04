'''
ID: 2010pes1
TASK: palsquare
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

def solve(n,nums):
    f = open("palsquare.out","w")
    for i in range (1,300+1):
        lst1 = convert(n,i,nums)
        lst2 = convert(n,i**2,nums)
        p = True
        for j in range(len(lst2)//2):
            if lst2[j] != lst2[len(lst2)-1-j]:
                p = False
                break
        if p:
            f.write(f"{lst1} {lst2}\n") 
    f.close()

def main():
    f = open("palsquare.in", "r")
    n = int(f.read().strip())
    nums = {}
    for i in range(0,9+1):
        nums[i] = str(i)
    for i in range(10,20+1):
        nums[i] = str(chr(55+i))
    solve(n,nums)
    f.close()

if __name__ == "__main__":
    main()
