class ArrayQueue:
    #基于环形数组实现的队列
    def __init__(self, size:int):
        self._nums = [0]*size
        self._front = 0
        self._rear = 0
        self._size = 0
    #容量
    def capacity(self)->int:
        return len(self._nums)
    #长度
    def size(self)->int:
        return self._size
    #判空
    def is_empty(self)->bool:
        return self._size==0
    #判满
    def is_full(self)->bool:
        return self._size==self.capacity()
    #入队
    def push(self,val:int):
        if self.is_full():
            raise Exception("Queue is full")
        self._nums[self._rear] = val
        self._rear = (self._rear+1)%self.capacity()
        self._size+=1
    #出队
    def pop(self)->int:
        if self.is_empty():
            raise Exception("Queue is empty")
        val = self._nums[self._front]
        self._front = (self._front+1)%self.capacity()
        self._size-=1
        return val
    #获取队头元素
    def peek(self)->int:
        if self.is_empty():
            raise Exception("Queue is empty")
        return self._nums[self._front]
    #打印
    def to_list(self)->list[int]:
        res = []
        for i in range(self._size):
            res.append(self._nums[(self._front+i)%self.capacity()])
        return res