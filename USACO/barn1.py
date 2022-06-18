'''
ID: 2010pes1
TASK: barn1
LANG: PYTHON3

Failing case:
M (max number of boards)
S (total number of stalls)
C (occupied stall numbers)
(too long for the margins of this terminal, i.e. check barn1.in)

Expected Ans:
100

Given ans:
195
'''

def solve(m,s,c,lst):
    lst.sort()
    star = lst[0]
    fin = lst[-1]
    count = 0
    countalt = 0
    outmove = []
    i = star
    print(lst[count])
    while i < fin+1:
        countalt = 0
        while (i <= lst[count]):
            print(count//5,lst[count],end=' ')
            countalt += 1
            i += 1
        if (countalt > 0):
            outmove.append(countalt)
            print(countalt)
            d+=1
        count += 1
        i+=1
    outmove.sort()
    ans =  c

    print(len(lst),d,sum(outmove),c,sum(outmove[:-(m-1)]),len(outmove))

    if (len(outmove)>m):
        ans += sum(outmove[:-(m-1)])
    else:
        ans = c if m > c else sum(outmove)

    return ans

def main():
    f = open("barn1.in","r")
    (m,s,c) = map(int, f.readline().strip().split(" "))
    lst = []
    for i in range(c):
        lst.append(int(f.readline().strip()))
    f.close()
    ans = solve(m,s,c,lst)
    f = open("barn1.out","w")
    f.write(f"{ans}\n")

if __name__=="__main__":
    main()
