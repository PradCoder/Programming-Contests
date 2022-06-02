'''
ID: 2010pes1
TASK: namenum
LANG: PYTHON3
'''

def solve(lst, dial, rdial, numstr):
    mklst = []
    preplst = [i for i in lst if (len(i) == len(numstr))] 
    for word in preplst:
        recstr = ''
        for ch in word:
            if ch in rdial:
                recstr += rdial[ch]
        if numstr == recstr:
            mklst.append(word)
    return mklst

def main():
    dial = {}
    f = open("dict.txt","r")

    lst = f.read().strip().split('\n')
    #print(lst) 
    f.close()
    f = open("namenum.in", "r")
    numstr = f.read().strip()
    f.close()

    dial['2'] = "ABC"
    dial['3'] = "DEF"
    dial['4'] = "GHI"
    dial['5'] = "JKL"
    dial['6'] = "MNO"
    dial['7'] = "PRS"
    dial['8'] = "TUV"
    dial['9'] = "WXY"

    rdial = {}
    for i in dial:
        for j in range(3):
            rdial[dial[i][j]] = i
    
    f = open("namenum.out", "w")
    ans = solve(lst,dial,rdial,numstr)
    if len(ans) == 0:
        f.write(str("NONE")+'\n')
    else:
        for i in ans:
            f.write(str(i)+'\n')
    f.close()

if __name__ == "__main__":
    main()
