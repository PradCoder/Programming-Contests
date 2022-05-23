'''
ID: 2010pes1
TASK: transform
LANG: PYTHON3
'''
def solve1(lstb,lsta):
    n = len(lstb)
    for i in range(n):
        for j in range(n):
            if(lstb[i][j] != lsta[j][n-1-i]):
                return False
                break
    return True

def solve2(lstb,lsta):
    n = len(lsta)
    for i in range(n):
        for j in range(n):
            if(lstb[i][j] != lsta[n-1-i][n-1-j]):
                return False
                break
    return True

def solve3(lstb,lsta):
    n = len(lsta)
    for i in range(n):
        for j in range(n):
            if(lstb[i][j] != lsta[n-1-j][i]):
                return False
                break
    return True
                
def solve4(lstb,lsta):
    n = len(lsta)
    for i in range(n):
        for j in range(n):
            if(lstb[i][j] != lsta[i][n-1-j]):
                return False
                break
    return True

def solve5(lstb,lsta):
    n = len(lsta)
    reflst = [(""*n) for i in range(n)]
    for i in range(n):
        for j in range(n):
            reflst[i] += lstb[i][n-1-j]
    
    if(solve1(reflst,lsta) or solve2(reflst,lsta) or solve3(reflst,lsta)):
        return True
    return False

def solve6(lstb,lsta):
    n = len(lsta)
    for i in range(n):
        for j in range(n):
            if (lstb[i][j] != lsta[i][j]):
                return False

    return True

def main():
    f = open("transform.in")
    n = int(f.readline())
    lstb,lsta = [],[]
    for i in range(n):
        lstb.append(f.readline().strip())
    for i in range(n):
        lsta.append(f.readline().strip())
    f.close()
    f = open("transform.out","w")
    if(solve1(lstb,lsta)):
        f.write("1");
    elif(solve2(lstb,lsta)):
        f.write("2");
    elif(solve3(lstb,lsta)):
        f.write("3");
    elif(solve4(lstb,lsta)):
        f.write("4")
    elif(solve5(lstb,lsta)):
        f.write("5")
    elif(solve6(lstb,lsta)):
        f.write("6")
    else:
        f.write("7")
    f.write("\n")
    f.close()
if __name__ == "__main__":
    main()
