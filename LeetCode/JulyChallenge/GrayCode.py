class Solution:
    def grayCode(self, n: int) -> List[int]:
        # 1[0,1]
        # 2[0,1,3,2]
        # 3[0,1,3,2,6,7,5,4]
        # 4[0,1,3,2,6,7,5,4,,,,9,10,11,9,8]
        lst = [0,1]
        for i in range (1,n):
            nl = lst[len(lst)-(2**(i-1)):]
            # print(nl)
            nlin = list(map(lambda x: x+(2**(i-1)),nl))
            mlin = list(map(lambda x: x+(2**(i)),nl))
            mlin.reverse()
            lst = lst+mlin+nlin
        return lst
