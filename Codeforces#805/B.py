def main():
    t = int(input())
    s = set()
    for i in range(t):
        m = input()
        c = 0
        for j in range(len(m)):
            s.add(m[j])
            if(len(s) > 3):
                c+=1
                s = set()
                ed = j
        print(ed, len(m) - 1)
        if(ed != len(m)-1):
            c+=1
        print(c)

if __name__ == "__main__":
    main()
