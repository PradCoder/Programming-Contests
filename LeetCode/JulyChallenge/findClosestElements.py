class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        arr.sort(key=(lambda z : abs(z-x)))
        lst = arr[:k]
        lst.sort()
        return lst
