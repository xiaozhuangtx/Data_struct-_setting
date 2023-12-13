class ArrayDeque:
    """双端队列的数组实现"""
    def __init__(self):
        self._nums=[]
        self._front=self._rear=0
        self._size=0
    #长度
    def size(self)->int:
        return self._size
    #容量
    def capacity(self)->int:
        return len(self._nums)
    #判空
    def is_empty(self)->bool:
        return self._size==0
    #扩容
    def _resize(self):
        new_nums = [None]*self.capacity()*2
        for i in range(self._size):
            new_nums[i]=self._nums[(self._front+i)%self.capacity()]
        self._nums=new_nums
        self._front=0
        self._rear=self._size-1
    #入队
    def push(self,num:int,is_front:bool):
        if self._size==self.capacity():
            self._resize()
        if self.is_empty():
            self._nums.append(num)
        elif is_front:
            self._front = (self._front-1)%self.capacity()
            self._nums[self._front]=num
        else:
            self._rear = (self._rear+1)%self.capacity()
            self._nums[self._rear]=num
        self._size+=1
    def index(self,i:int)->int:
        return self._nums[(self._front+i)%self.capacity()]
    def push_first(self,num:int):
        self.push(num,True)
    def push_last(self,num:int):
        self.push(num,False)
    #出队
    def pop(self,is_front:bool)->int:
        if self.is_empty():
            raise Exception("Deque is empty")
        if is_front:
            val = self._nums[self._front]
            self._front = (self._front+1)%self.capacity()
        else:
            val = self._nums[self._rear]
            self._rear = (self._rear-1)%self.capacity()
        self._size-=1
        return val
    #队首出队
    def pop_first(self)->int:
        return self.pop(True)
    #队尾出队
    def pop_last(self)->int:
        return self.pop(False)
    #访问队首
    def peek_first(self)->int:
        if self.is_empty():
            raise Exception("Deque is empty")
        return self._nums[self._front]
    #访问队尾
    def peek_last(self)->int:
        if self.is_empty():
            raise Exception("Deque is empty")
        return self._nums[self._rear]
    #打印
    def to_array(self)->list:
        return [self._nums[(self._front+i)%self.capacity()] for i in range(self._size)]
    
if __name__ == "__main__":
    deque = ArrayDeque()
    deque.push_first(1)
    deque.push_first(2)
    deque.push_last(3)
    deque.push_last(4)
    print(deque.to_array())
    print(deque.pop_first())
    print(deque.pop_last())
    print(deque.to_array())
    print(deque.peek_first())
    print(deque.peek_last())
    print(deque.to_array())