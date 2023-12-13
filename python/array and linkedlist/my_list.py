class Mylist:
    """列表简易实现"""
    def __init__(self):#self表示实例对象本身
        self._capacity:int=10  #"_"表示私有变量
        self._arr:list[int]=[0]*self._capacity #初始化数组
        self._size:int=0 
        self._extend_ratio:int=2
    def size(self)->int:
        return self._size
    def capacity(self)->int:
        return self._capacity
    def get(self,index:int)->int:
        if index<0 or index>=self._size:
            raise Exception("Index out of bound")
        return self._arr[index]
    def set(self,index:int,value:int):
        if index<0 or index>=self._size:
            raise Exception("Index out of bound")
        self._arr[index]=value
    def extend_capacity(self):
        self._capacity*=self._extend_ratio
        new_arr=[0]*self._capacity
        for i in range(self._size):
            new_arr[i]=self._arr[i]
        self._arr=new_arr
    def add(self,num:int):
        if self._size==self._capacity:
            self.extend_capacity()
        self._arr[self._size]=num
        self._size+=1
    def insert(self,index:int,value:int):
        if index<0 or index>=self._size:
            raise Exception("Index out of bound")
        if self._size==self._capacity:
            self.extend_capacity()
        for i in range(self._size-1,index,-1):
            self._arr[i]=self._arr[i+1]
        self._arr[index]=value ##在第index个位置之
        self._size+=1
    def remove(self,index:int)->int:
        if index<0 or index>=self._size:
            raise Exception("Index out of bound")
        value=self._arr[index]
        for i in range(index+1,self._size):
            self._arr[i-1]=self._arr[i]
        self._size-=1
        return value