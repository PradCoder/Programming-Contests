'''
ID: 2010pes1
TASK: milk
LANG: PYTHON3
'''
def solve(n,m,lst):
    #start with the cheapest and buy all
    #since the units are the value we care the price will have a min
    acc = 0
    lst.sort(key=lambda x: x[0])
    for i in range(len(lst)):
        if n >= lst[i][1]:
            m -= lst[i][1]
            acc += lst[i][0] * lst[i][1]
        else:
            acc += lst[i][0] * n
            break
        print(acc)
    return acc
def main():
    f = open("milk.in","r")
    n, m = map(int,f.readline().strip().split(" "))
    lst = []
    for i in range(m):
        p, a = map(int,f.readline().strip().split(" "))
        lst.append((p,a))
    f.close()
    val = solve(n,m,lst)
    f = open("milk.out","w")
    f.write(f"{val}\n")
    f.close()

if __name__=="__main__":
    main()
