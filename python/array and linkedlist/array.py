## array
# 1. random access
def random_access(nums:list[int],index:int):
    if index<0 or index>=len(nums):
        raise Exception("Index out of bound")#抛出异常
    return nums[index]
# 2. insert
def insert(nums:list[int],index:int,value:int):
    if index<0 or index>len(nums):
        raise Exception("Index out of bound")
    nums.append(0)
    for i in range(len(nums)-1,index,-1):
        nums[i]=nums[i-1]
    nums[index]=value
# 3. delete
def delete(nums:list[int],index:int):
    if index<0 or index>=len(nums):
        raise Exception("Index out of bound")
    for i in range(index,len(nums)-1):
        nums[i]=nums[i+1]
# 4. print
def print_array(nums:list[int]):
    count  = 0
    for i in range(len(nums)):
        print(nums[i],end=' ')
    for num,index in enumerate(nums):
        count+=nums[i]
        count+=num
    print()
# 5. search
def search(nums:list[int],value:int):
    for i in range(len(nums)):
        if nums[i]==value:
            return i
    return -1
#6. extend
def extend(nums:list[int],enlarge:int)->list[int]:
    #nums.append(value)
    res=[0]*(len(nums)+enlarge)
    for i in range(len(nums)):
        res[i]=nums[i]
    return res

def main():
    arr:list[int]=[0]*5 # [0,0,0,0,0]  #分号后表示类型注解，不是必须的
    nums:list[int]=[1,2,3,4,5] 
    arr1=[0]*5 # [0,0,0,0,0]
    nums1=[1,2,3,4,5]
    print(arr1)
    print(nums1)
    print('------------------')
    ## random access
    print(random_access(nums,3))
    #print(random_access(nums,100))
    ## insert
    insert(nums,2,100)
    print(nums)
    ## delete
    delete(nums,2)
    print(nums)
    ## print
    print_array(nums)
    ## search
    print(search(nums,3))
    print(search(nums,100))
    ## extend
    print(extend(nums,5))
    print(nums)

if __name__ == "__main__":
    main()