def solve(dial, numstr):
    formLST = []
    for ch in numstr:
        for i,j in dial.items():    
            if ch == i:
                formLST.append(j)

    for i in range(len(numstr)):

def main():
    dial = {}
    f = open("dict.txt","r")

    lst = f.read().strip().split('\n')
    print(lst) 
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
    
    f = open("namenum.out", "w")
    f.write(solve(dial,numstr))
    f.close()

if __name__ == "__main__":
    main()
