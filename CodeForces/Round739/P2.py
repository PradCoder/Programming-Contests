def solver(a,b,c):
    r = abs(a-b)
    d = 2*r
    if((a+r)%d != b or (b-r)%d !=a or (b+r)%d !=a or (a-r)%d != b or c>d):
        print(-1)
    else:
        print((d if (c+r)%d == 0 else (c+r)%d))

n = int(input())

for i in range(n):
    (a,b,c) = map(int,input().split())
    solver(a,b,c)
    