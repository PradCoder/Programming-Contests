dic = {}
dicd = {}
dicr = {}

INF = 9876543210
def dijkstra(src,dicd, dicr):


def solve(lst):
    global INF, dic
    lenl = len(lst)
    dicd = {a:INF for a in lst}
    dicr = {a:-1 for a in lst}
    vis = {a:False for a in lst}
    dic["English"] = 0
    for i in lst:
        v = ""
        for j in lst:
            if(not vis[j] and (v == "" or dicd[j] < dicd[v])):
                v = j

        if(dicd[v] == INF)
            break

        vis[v] = True
        for key,val in dic:
    

def main():
    global dic
    n,m = map(int,input().split())
    lang = input().split()
    dic = {a:[] for a in lang}
    for i in m:
        x,y,z = input().split()
        c = int(z)
        dic[x].append(y,c)
        dic[y].append(x,c)
    print(solve(lang))

if __name__ == "__main__":
    main()
