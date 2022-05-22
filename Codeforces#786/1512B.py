def solve1(p1.p2,ls):
    distx = abs(p1[0]-p2[0])
    disty = abs(p1[1]-p2[1])
    if(distx == 0):
        ls[][]
    elif(disty == 0):

def solve(n, ls):
    i = 0
    x1,y1 = -1,-1
    x2,y2 = -1,-1
    for i in range(n):
        if '*' in ls[i]:
            if (x1 == -1):
                x1 = i
            else:
                x2 = i
                for j in range(n):
                    if ls[i][j] == "*":
                        if (y1 == -1):
                            y1 = j
                        else:
                            y2 = j
    solve1((x1,y1),(x2,y2), ls)
def main():                 
    t = int(input())
    for i in range(t):
        n = int(input())
        ls = []
        for j in range(n):
            ls1 = list(input().split())
            ls.append(ls1)
        print(solve(n,ls))
    
if __name__ == "__main__":
    main()