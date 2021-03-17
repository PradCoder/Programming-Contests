def solve():
    
    return round(ans,2)


def main():
    n = int(input())
    lst = [(0,0,0,0,0)] * n
    
    for i in range(n):
        x,y,z,r,v = map(int,input().split())
        lst.append((x,y,z,r,v))
    
    print(solve(lst))
