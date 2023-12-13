import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import ListNode

class LinkedListStack:
    # 初始化栈
    def _init_(self):
        self._peek :ListNode = None 
        self.size = 0
    # 长度
    def size(self)->int:
        return self.size
    # 判空
    def is_empty(self)->bool:
        return self.size==0
    # 入栈
    def push(self,val:int):
        node = ListNode(val)
        node.next = self._peek
        self._peek = node
        self.size+=1
    # 出栈
    def pop(self)->int:
        if self.is_empty():
            raise Exception("Stack is empty")
        node = self._peek
        self._peek = node.next
        node.next = None
        self.size-=1
        return node.val
    # 获取栈顶元素
    def peek(self)->int:
        if self.is_empty():
            raise Exception("Stack is empty")
        return self._peek.val
    # 打印
    def to_list(self)->list[int]:
        res = []
        cur = self._peek
        while cur:
            res.append(cur.val)
            cur = cur.next
        res.reverse()
        return res
    