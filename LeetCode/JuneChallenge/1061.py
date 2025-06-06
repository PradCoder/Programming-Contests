class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        dic = {}
        ans = ""
        
        # Use union find or some path reduction
        for i in range(len(s2)):
            if (s1[i] not in dic) or (s2[i] not in dic):
                dic[s1[i]] = [s1[i]]
                dic[s2[i]] = [s2[i]]
            dic[s1[i]].append(s2[i])
            dic[s2[i]].append(s1[i])
        
        print(dic)
        for i in dic:
            dic[i].sort()

        for i in baseStr:
            ans += dic[i][0]

        return ans

def main():
    a = Solution();
    s1 = "parker"
    s2 = "morris"
    baseStr = "parser"
    print(a.smallestEquivalentString(s1, s2, baseStr))

if __name__ == "__main__":
    main()
