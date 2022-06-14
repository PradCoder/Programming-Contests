'''
ID: 2010pes1
TASK: barn1
LANG: PYTHON3

Failing case:
50 200 10
18
69
195
38
73
28
6
172
53
99

Expected Ans:
10

Given ans:
190
'''
def solve(m,s,c,lst):
    lst.sort()
    star = lst[0]
    fin = lst[-1]
    count = 0
    countalt = 0
    outmove = []
    i = star
    while i < fin+1:
        countalt = 0
        while (i < lst[count]):
            countalt += 1
            i += 1
        if (countalt > 0):
            outmove.append(countalt)
        count += 1
        print(countalt)
        i+=1
    outmove.sort()
    ans =  c
    if (len(outmove)>m):
        ans += sum(outmove[:-(m-1)])
    else:
        ans += sum(outmove)
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
