'''
ID: 2010pes1
TASK: namenum
LANG: PYTHON3
'''
def subrecurse(i,n,formLST):
    if n==0:
        return ''
    else:
        for j in range(3):
            return (formLST[i][j]+subrecurse(i+1,n-1,formLST))

def recurse(i,k,n,formLST):
    lst = []
    if n == 0:
        return ['']
    else:
        for j in range(3):
            lst.append([formLST[0][k]]+recurse(1,0,n-1,formLST)+recurse(2,0,n-1,formLST))
            lst.append([formLST[0][k]]+recurse(1,1,n-1,formLST)+recurse(2,1,n-1,formLST))
            lst.append([formLST[0][k]]+recurse(1,2,n-1,formLST)+recurse(2,2,n-1,formLST))

    print(lst)
    return lst

def solve(dial, numstr):
    formLST = []
    for ch in numstr:
        for i,j in dial.items():
            if ch == i:
                formLST.append(j)
    newlst = recurse(0,0,len(numstr),formLST)

def main():
    dial = {}
    f = open("dict.txt","r")

    lst = f.read().strip().split('\n')
    #print(lst) 
    f.close()
    f = open("namenum.in", "r")
    numstr = f.read().strip()
    print(numstr)
    f.close()

    dial['2'] = "ABC"
    dial['3'] = "DEF"
    dial['4'] = "GHI"
    dial['5'] = "JKL"
    dial['6'] = "MNO"
    dial['7'] = "PRS"
    dial['8'] = "TUV"
    dial['9'] = "WXY"
    
    f = open("namenum.out", "w")
    f.write(str(solve(dial,numstr)))
    f.close()

if __name__ == "__main__":
    main()
