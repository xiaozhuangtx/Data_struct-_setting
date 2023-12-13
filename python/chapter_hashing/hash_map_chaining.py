class HashMapChaining:
    "链式哈希表"
    def __init__(self):
        self.size = 0  # 键值对的数量
        self.capacity = 4  # 哈希表的容量
        self.load_thres=2.0/3.0 # 负载因子阈值
        self.extend_ratio=2     #   扩容比例
        self.buckets = [[] for _ in range(self.capacity)]  # 桶数组，每个桶是一个列表
    def hash_func(self, key):
        """哈希函数"""
        return key % self.capacity
    def load_factor(self):
        """负载因子"""
        return self.size/self.capacity # 哈希表中元素的个数/哈希表的容量
    
    def get(self, key):
        """查询元素"""
        index = self.hash_func(key)
        bucket = self.buckets[index]
        for pair in bucket:
            if pair.key == key:
                return pair.value
        raise KeyError
    def extend(self):
        """扩容"""
        # 保存旧的桶数组
        old_buckets = self.buckets
        # 创建新的桶数组
        self.capacity *= self.extend_ratio
        self.buckets = [[] for _ in range(self.capacity)]
        # 把旧桶数组中的元素添加到新桶数组中
        for bucket in old_buckets:
            for pair in bucket:
                index = self.hash_func(pair.key)
                self.buckets[index].append(pair)
                
    def put(self, key, value):
        """添加元素"""
        if self.load_factor()>self.load_thres:
            self.extend()
        index = self.hash_func(key)
        bucket = self.buckets[index]
        for pair in bucket:
            if pair.key == key:
                pair.value = value
                return
        # 没有找到相同的键，添加新的键值对
        bucket.append(Pair(key, value))
        self.size += 1
            
    def remove(self, key):
        """删除元素"""
        index = self.hash_func(key)
        bucket = self.buckets[index]
        for i, pair in enumerate(bucket):  #enumerate() 函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标
            if pair.key == key:
                bucket.pop(i)
                self.size -= 1
                return
        raise KeyError
    def print(self):
        """打印哈希表"""
        for bucket in self.buckets:
            res=[]
            for pair in bucket:
                res.append((pair.key,pair.value))
            print(res)