def solve(N,X,Y):
    c = C.copy()
    cost = 0
    for i in range(N-1):
        x = min(c[i:])
        #print(x)
        j = c[i:].index(x)+len(c[:i])
        cost += (j-i)+1
        c = c[:i]+c[i:j+1][::-1]+c[j+1:]
    return cost

def main():
    T = int(input())
    for i in range(T):
        C = list(input().split())
        X,Y = map(int,C[:2])
        S = C[2]
        lst = [S[i]+S[i+1] for i in range(len(S)-1)]
        #print(lst)    
        # mx = C*(C-1)-((C-1)*C)/2
        # print("Case #{n}: ".format(i),end="")
        # if(C>= N-1 and C<=mx):
        #     print(solve(N,C))
        # else:
        #     print("IMPOSSIBLE")
        print("Case #{}: ".format(i+1),solve(lst,X,Y))

if __name__ == "__main__":
    main()