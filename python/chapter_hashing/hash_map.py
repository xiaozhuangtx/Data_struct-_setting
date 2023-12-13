#初始化 hash map
hmap:dict={}
#添加元素
#在哈希表中添加键值对（key,value）
hmap[12836]='a' #添加一个键值对 key=12836,value='a'
hmap[12837]='b' 
hmap[12838]='c'
hmap[12839]='d'
hmap[12840]='e'

#查询元素
#通过键值查询元素
name=hmap[12836]
print(name)

#删除元素
hmap.pop(12836)
print(hmap)


#遍历
for key,value in hmap.items():
    print(key,"->",value)
    
#单独遍历键
for key in hmap.keys():
    print(key)
    
#单独遍历值
for value in hmap.values():
    print(value)
    