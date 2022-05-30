'''
ID: 2010pes1
TASK: namenum
LANG: PYTHON3
'''
def recurse(formLST,i,n,lenstr):
    if n == lenstr:
        return ''
    else:
        return [ formLST[n][0] + recurse(formLST,0,n+1,lenstr)
               , formLST[n][0] + recurse(formLST,1,n+1,lenstr)
               , formLST[n][0] + recurse(formLST,2,n+1,lenstr)
               , formLST[n][1] + recurse(formLST,0,n+1,lenstr)
               , formLST[n][1] + recurse(formLST,1,n+1,lenstr)
               , formLST[n][1] + recurse(formLST,2,n+1,lenstr)
               , formLST[n][2] + recurse(formLST,0,n+1,lenstr)
               , formLST[n][2] + recurse(formLST,1,n+1,lenstr)
               , formLST[n][2] + recurse(formLST,2,n+1,lenstr)
                ]
'''
G - P
  - R
  - S

H - P
  - R 
  - S

I - P 
  - R 
  - S
'''           
def recurse(i,z,n,formLST):
    lst = []
    for j in range(len(formLST[0])):
        for k in range(len(formLST[1])):
            for l in range(len(formLST[2])):
                for m in range(len(formLST[3])):
                    lst.append(formLST[0][j]+formLST[1][k]+formLST[2][l]+formLST[3][m])
    print(lst)
    return lst

def solve(lst,dial, numstr):
    formLST = []
    for ch in numstr:
        for i,j in dial.items():
            if ch == i:
                formLST.append(j)
    newlst = recurse(0,0,len(numstr),formLST)
    preplst = [i for i in lst if (len(i) == len(numstr)) ] 

    for i in newlst:
        for j in preplst:
            if i == j:
                return i
    return "NONE"

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
    f.write(str(solve(lst,dial,numstr)))
    f.close()

if __name__ == "__main__":
    main()
