n,m = map(int, input().split())
g = [[] for i in range(n+1)]

for _ in range(m):
    u,v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
    
cut = 0
def dfs(x, p):
    global cut
    sm = 1
    for w in g[x]:
        if w != p:
            # must be a parent
            sm += dfs(w,x)
    if sm % 2 == 0:
        cut += 1
    return sm

dfs(1,None)

print(cut-1)
