class ArrayStakc:
    # 初始化栈
    def __init__(self):
        self._stack:list[int]=[]
    #获取栈的大小
    def size(self)->int:
        return len(self._stack)
    #判空
    def is_empty(self)->bool:
        return self._stack==[]
    #入栈
    def push(self,val:int):
        self._stack.append(val)
    #出栈
    def pop(self)->int:
        if self.is_empty():
            raise Exception("Stack is empty")
        return self._stack.pop()  
    #获取栈顶元素
    def peek(self)->int:
        if self.is_empty():
            raise Exception("Stack is empty")
        return self._stack[-1]
    #打印
    def to_list(self)->list[int]:
        return self._stack      