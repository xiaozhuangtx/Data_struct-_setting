class LinkedListQueue:
    #基于链表实现的队列
    def __init__(self):
        self._front:ListNode = None
        self._rear:ListNode = None
        self._size:int = 0
    #长度
    def size(self)->int:
        return self._size
    #判空
    def is_empty(self)->bool:
        return self._size==0
    #入队
    def push(self,val:int):
        node = ListNode(val)
        if self.is_empty():
            self._front = node
        else:
            self._rear.next = node
        self._rear = node
        self._size+=1
    #出队
    def pop(self)->int:
        if self.is_empty():
            raise Exception("Queue is empty")
        node = self._front
        self._front = node.next
        node.next = None
        self._size-=1
        return node.val
    #获取队首元素
    def peek(self)->int:
        if self.is_empty():
            raise Exception("Queue is empty")
        return self._front.val
    #打印
    def to_list(self)->list[int]:
        res = []
        cur = self._front
        while cur:
            res.append(cur.val)
            cur = cur.next
        return res