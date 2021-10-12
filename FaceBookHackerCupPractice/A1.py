def solve(strs):
    sols = []
    for st in strs:
        freq = {}
        vowelCount = 0
        vowelDif = 0
        conDif = 0
        for i in st:
            if i in freq:
                freq[i] += 1
            else:
                freq[i] =  1

        for j in freq:
            if (j in {'A','E','I','O','U'}):
                vowelCount += freq[j]
                vowelDif += 1
            else:
                conDif += 1

        conCount = len(st)-vowelCount
        freq1 = dict(sorted(freq.items(),reverse = True, key= lambda x: x[1]))
        freq2 = [*freq1][0]
        sol = 0
        if (vowelDif == 1 or conDif == 1):
            if freq2 in {'A','E','I','O','U'}:
                sol += conCount
            else:
                sol += vowelCount
        else:
            if( conDif+vowelDif == conCount+vowelCount):
                sol = conCount + vowelCount
            else:
                sol = conCount + vowelCount + 1
        sols.append(sol)
    for j in range(len(sols)):
        print(f"Case #{j+1}: {sols[j]}")

def main():
    n = int(input())
    strs  = []
    for i in range(n):
        st = input()
        strs.append(st)
    solve(strs)

if __name__ == "__main__":
    main()
