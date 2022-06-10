'''
ID: 2010pes1
TASK: namenum
LANG: PYTHON3
'''
def solve(m,lst):
    sz = s//m 
    fsz = s-m*sz
    while (not folded):
        if condition:
            folded = True
    for i in range(m):
        print((lst[i]))
    return 0

def main():
    f = open("barn1.in","r")
    (m,s,c) = map(int, f.readline().strip().split(" "))
    lst = []
    for i in range(c):
        lst.append(int(f.readline().strip()))
    f.close()
    ans = solve(m,s,lst)
    f = open("barn1.out","w")
    f.write(f"{ans}\n")

if __name__=="__main__":
    main()
