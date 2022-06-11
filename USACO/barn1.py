'''
ID: 2010pes1
TASK: namenum
LANG: PYTHON3
'''
def solve(m,s,c,lst):
    star = lst[0]
    fin = lst[-1]
    count = 0
    countalt = 0
    for i in range(star,fin+1):
        if(i != lst[count]):
            countalt += 1
        else:
            count+=1
    #think about taking out the bigger spaces
    return countalt

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
