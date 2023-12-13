import collections
#初始化一个双端队列
deque:deque[int]=collections.deque()

#入队
deque.append(1)
deque.append(2)
deque.append(3)
print(deque)
#添加到队头
deque.appendleft(0)

#访问元素
front:int = deque[0]
print(front)
rear:int = deque[-1]
print(rear)

#出队
pop_front:int = deque.popleft()
pop_rear:int = deque.pop()
print(pop_front)
print(pop_rear)

#长度
size:int = len(deque)
print(size)

#判空
is_empty:bool = len(deque)==0
print(is_empty)
