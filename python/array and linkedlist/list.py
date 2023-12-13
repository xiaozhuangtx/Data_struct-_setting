


def main():
    ##初始化列表
    nums1:list[int]=[] # 空列表
    nums:list[int]=[1,2,3,4,5] # 非空列表
    ##访问列表
    print(nums[0]) # 1
    print(nums[1]) # 2
    ##修改列表
    nums[0]=100
    ##清空列表
    nums.clear()
    ##在尾部添加元素
    nums.append(1)
    nums.append(2)
    ##在指定位置添加元素
    nums.insert(0,100)
    nums.insert(1,200)
    ##删除尾部元素
    nums.pop()
    ##删除指定位置元素
    nums.pop(0)
    ##遍历列表
    for i in range(len(nums)):
        print(nums[i],end=' ')
    print()
    ##拼接列表
    nums1=[1,2,3]
    nums2=[4,5,6]
    nums1+=nums2
    ##排序列表
    nums1.sort()#升序
    
    

if __name__ == "__main__":
    main()