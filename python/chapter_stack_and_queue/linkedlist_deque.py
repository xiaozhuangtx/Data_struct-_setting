class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        self.prev = None
class LinkedListDeque:
    #基于链表实现的双端队列
    def __init__(self) -> None:
        self._front = None
        self._rear = None
        self._size = 0
    #长度
    def size(self)->int:
        return self._size
    #判断是否为空
    def is_empty(self)->bool:
        return self._size==0
    #入队
    def push(self,num:int,is_front:bool):
        node = ListNode(num)
        if self.is_empty():
            self._front = node
            self._rear = node
        elif is_front:
            node.next = self._front
            self._front.prev = node
            self._front = node
        else:
            node.prev = self._rear
            self._rear.next = node
            self._rear = node
        self._size+=1
    #出队
    def pop(self,is_front:bool)->int:
        if self.is_empty():
            raise Exception("Deque is empty")
        if is_front:
            val = self._front.val
            self._front = self._front.next
            if self._front:
                self._front.prev = None
            else:
                self._rear = None
        else:
            val = self._rear.val
            self._rear = self._rear.prev
            if self._rear:
                self._rear.next = None
            else:
                self._front = None
        self._size-=1
        return val
    #获取队头元素
    def pop_firts(self)->int:
        return self.pop(True)
    def pop_last(self)->int:
        return self.pop(False)
    #打印
    def to_list(self)->list[int]:
        res = []
        cur = self._front
        while cur:
            res.append(cur.val)
            cur = cur.next
        return res
if __name__ == "__main__":
    deque = LinkedListDeque()
    deque.push(1,True)
    deque.push(2,True)
    deque.push(3,True)
    print(deque.to_list())
    deque.push(0,False)
    print(deque.to_list())
    front:int = deque.pop_firts()
    print(front)
    rear:int = deque.pop_last()
    print(rear)
    print(deque.to_list())
    size:int = deque.size()
    print(size)
    is_empty:bool = deque.is_empty()
    print(is_empty) 