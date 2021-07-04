class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], l: int) -> int:
        def Kadane(arr: List[int],k) -> int:
            ans,summ = arr[0], arr[0]
            for i in range(1,len(arr)):
                ans = max(ans, ans+arr[i])
                if ans > k:
                    ans = -1000000
                summ = max(summ, ans)
            return summ
        
        lst = []
        
        for i in range(len(matrix)):
            for j in range (1,len(matrix[i])+1):
                summ = 0
                k = 1
                while k < len(matrix[i]):
                    l = k
                    while (l-k)<j:
                        summ += matrix[i][l-1]
                        l+=1
                    lst.append(summ)
                    k+=j
                print(lst)
        print(lst)
        return 1 #Kadane(lst,k)
