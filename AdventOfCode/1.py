def main():
    suma, sumb = [], []
    f = open("input.txt","r")
    dic = {}
    for x in f:
        [a, b] = list(map(int,x.split()))
        if a not in dic:
            dic[a] = 0
        if b not in dic:
            dic[b] = 0
        if b in dic:
            dic[b]+=1
        suma.append(a)
        sumb.append(b)
    f.close()
    suma.sort()
    sumb.sort()
    print("Total Distance", sum([abs(b-a) for (a,b) in zip(suma,sumb)]))
    print("Similarity Score", sum([a*dic[a] for a in suma]))

if __name__=="__main__":
    main()
