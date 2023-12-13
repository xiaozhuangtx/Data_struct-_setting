class Pair:
    """键值对"""
    def __init__(self, key, value):
        self.key = key
        self.value = value

class ArrayHashMap:
    def __init__(self):
        self.buckets:list[Pair|None] = [None]*100 # 桶数组 list[Pair|None] 的|None表示桶数组中的元素类型可以是Pair或者None
    def hash_func(self, key):
        """哈希函数"""
        return key % 100
    def get(self,key:int)->str:
        """查询元素"""
        index=self.hash_func(key)
        pair=self.buckets[index]
        if pair is None:
            raise KeyError
        return pair.value
    def put(self,key:int,value:str):
        """添加元素"""
        index=self.hash_func(key)
        self.buckets[index]=Pair(key,value)
    def remove(self,key:int):
        """删除元素"""
        index=self.hash_func(key)
        self.buckets[index]=None
    def entry_set(self):
        """遍历"""
        result:list[Pair]=[]
        for pair in self.buckets:
            if pair is not None:
                result.append(pair)
        return result
    def key_set(self):
        """单独遍历键"""
        result:list[int]=[]
        for pair in self.buckets:
            if pair is not None:
                result.append(pair.key)
        return result
    def values(self):
        """单独遍历值"""
        result:list[str]=[]
        for pair in self.buckets:
            if pair is not None:
                result.append(pair.value)
        return result
    
    def print(self):
        """打印哈希表"""
        for pair in self.buckets:
            if pair is not None:
                print(pair.key,"->",pair.value)