from collections import deque
que:deque[int] = deque()
que.append(1)
que.append(2)
que.append(3)
print(que)
front:deque[int] = que[0]
print(front)
pop:deque[int] = que.popleft()
print(pop)
size:int = len(que)
print(size)
is_empty:bool = len(que)==0
print(is_empty)