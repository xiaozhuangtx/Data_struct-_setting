import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from chapter_hashing.array_hash_map import Pair

class HashMapOpenAddressing:
    """开放寻址法实现的哈希表"""
    def __init__(self):
        self.size=0 # 哈希表中元素的个数 
        self.capacity=8 # 哈希表的容量 
        self.load_factor=0.75 # 装载因子
        self.extend_ratio=2 # 扩容比例
        self.buckets:list[Pair|None]=[None]*self.capacity # 哈希表的桶
        self.TOMBSTONE=Pair(-1,"-1") # 哈希表的墓碑
        
    def hash(self,key:int)->int:
        """哈希函数"""
        return key%self.capacity
    
    def load_factor(self)->float:
        """获取装载因子"""
        return self.size/self.capacity
    
    def find_bucket(self,key:int)->int:
        """查找元素所在的桶"""
        index=self.hash(key)
        first_tombstone=-1  #用来   记录第一个墓碑的位置和判断是否有墓碑
        while self.buckets[index] is not None: # 如果桶不为空 则
            if self.buckets[index].key==key: # 如果桶中的元素的key等于要查找的key 则返回index
                if first_tombstone!=-1:
                    self.buckets[first_tombstone]=self.buckets[index]
                    self.buckets[index]=self.TOMBSTONE
                    return first_tombstone
                return index
            if first_tombstone==-1 and self.buckets[index]==self.TOMBSTONE: #没有找到墓碑 并且当前桶中的元素是墓碑 则记录墓碑的位置
                first_tombstone=index
            index=(index+1)%self.capacity
        return index if first_tombstone==-1 else first_tombstone # 如果没有找到墓碑 则返回index 否则返回first_tombstone