# 初始化栈
# python 没有栈的概念，但是可以用list来实现栈的功能
stack:list[int]=[] # :list[int]表示类型注解，不是必须的
stack1=[]
print(stack)
print(stack1)
# 入栈
stack.append(1)
stack.append(2)
stack.append(3)
stack.append(4)
stack.append(5)

# 访问栈顶元素
peek:int=stack[-1]
print(peek)
# 出栈
val:int=stack.pop()
print(val)
# 判断栈是否为空
is_empty:bool=len(stack)==0
print(is_empty)
# 获取栈的大小
size:int=len(stack)
print(size)