class MaxHeap:
    def __init__(self, heapSize):
        self.heapSize = heapSize
        self.maxheap = [0] * (heapSize + 1)
        self.realSize = 0

    def add(self, element):
        self.realSize += 1
        if self.realSize > self.heapSize:
            print("Added too many elements!")
            self.realSize -= 1
            return

        self.maxheap[self.realSize] = element
        index = self.realSize
        parent = index // 2
        
        while (self.maxheap[index] > self.maxheap[parent] and index > 1):
            self.maxheap[parent], self.maxheap[index] = self.maxheap[index],self.maxheap[parent]
            index = parent
            index = parent
            parent = index // 2

    def peek(self):
        return self.maxheap[1]

    def pop(self):
        if self.realSize < 1:
            print("Don't have any element!")
            return -sys.maxsize
        else:
            removeElement = self.maxheap[1]
            self.maxheap[1] = self.maxheap[self.realSize]
            self.realSize -= 1
            index = 1
            while (index <= self.realSize // 2):
                left = index * 2
                right = (index * 2) + 1
                if (self.maxheap[index] < self.maxheap[left] or self.maxheap[index] < self.maxheap[right]):
                    if self.maxheap[left] > self.maxheap[right]:
                        self.maxheap[left], self.maxheap[index] = self.maxheap[index], self.maxheap[left]
                        index = left
                    else:
                        self.maxheap[right], self.maxheap[index] = self.maxheap[index], self.maxheap[right]
                        index = right
                else:
                    break
            return removeElement

    def size(self):
        return self.realSize

    def __str__(self):
        return str(self.maxheap[1 : self.realSize + 1])

if __name__ == "__main__":
    maxHeap = MaxHeap(5)
    maxHeap.add(1)
    maxHeap.add(2)
    maxHeap.add(3)
    
    print(maxHeap)

    print(maxHeap.peek())

    print(maxHeap.pop())
    
    print(maxHeap.pop())

    print(maxHeap.pop())
    maxHeap.add(4)
    maxHeap.add(5)

    print(maxHeap)
