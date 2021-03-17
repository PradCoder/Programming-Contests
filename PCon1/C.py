def genR(key):
    str = ""
    for i in key:
        str+= chr(ord("A")+(26-(ord(i)-ord("A"))) % 26)
    return str

def chunkUp(str1,n):
    lst = []
    i = 0
    lens = len(str1)
    while i < lens:
        s = ""
        j = 0
        while j < n:
            if i+j < lens:
                s+= str1[i+j]
            j+=1
        i+=n
        lst.append(s)
    return lst

def decrypt(str1,key):
    revKey = genR(key)
    lenR = len(revKey)
    sol = ""
    orda = ord("A")
    for i in range(len(str1)):
        sol += chr(orda + (ord(str1[i]) - orda + ord(revKey[i%lenR]) -orda)%26)
    return sol

def solve(str1, key):
    chunkedStr = chunkUp(str1,len(key))
    lenC = len(chunkedStr)
    solLst = ["" for i in range(lenC)]
    solLst[0] = decrypt(chunkedStr[0],key)
    for i in range(1,lenC):
        solLst[i] = decrypt(chunkedStr[i],solLst[i-1])
    sol = solLst[0]
    for i in range(1,lenC):
        sol+=solLst[i]
    return sol

def main():
    str1 = input()
    str2 = input()
    print(solve(str1,str2))

if __name__ == "__main__":
        main()
