from math import ceil

def main():
    t = int(input())
    for j in range(t):
        n,m = map(int,input().split())
        x = input()
        s = input()
        i = 0
        ca = m//n+1
        if(x in s):
            i = ceil(n/m)
        while (not s in x) and i <= (ca) :
            x = x+x
            if (x in s
            i+=1
        if (i <= ca):
            print(i)
        else:
            print(-1)

if __name__ == "__main__":
    main();
