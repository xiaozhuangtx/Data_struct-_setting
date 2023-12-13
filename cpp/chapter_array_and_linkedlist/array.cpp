#include "../utils/common.hpp"
// 随机访问
int randomAccess(int *arr, int size){
    // 在区间[0, size)内随机选取一个索引
    int randomIndex = rand() % size;
    // 返回索引对应的元素
    return arr[size];
}
// 插入元素
void insert(int *nums,int size,int num,int index){
    //把索引index之后的元素都向后移动一位
    for(int i=size-1;i>index;i--){
        nums[i]=nums[i-1];
    }
    //把新元素放到索引index的位置
    nums[index]=num;
}
void Insert(int *nums,int size,int num){
    for(int i=0;i<size;i++){
        if(nums[i]>num){
            insert(nums,size,num,i);
            break;
        }
    }
}
void Inverse(int *arr){
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len/2;i++){
        int temp = arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=temp;
    }
}
// 删除元素
void remove(int *nums,int size,int index){
    //把索引index之后的元素都向前移动一位
    for(int i=index;i<size-1;i++){
        nums[i]=nums[i+1];
    }

}
// 遍历数组
void traverse(int *nums,int size){
    for(int i=0;i<size;i++){
        cout<<nums[i]<<'\t';
    }
    cout<<endl;
}
// 查找元素
int find(int *nums,int size,int num){
    for(int i=0;i<size;i++){
        if(nums[i]==num){
            return i;
        }
    }
    return -1;
}
// 扩容数组
int *extend(int *nums,int size,int enlarge){
    int *res = new int[size+enlarge];
    for(int i=0;i<size;i++){
        res[i]=nums[i];
    }
    nums=res;
    return res;
}
int main(){
    // 创建数组
    int arr[5] = {1, 2, 3, 4, 5};
    int nums[5]={1,2,3,4,5};
    cout << arr[0]<< endl;
    cout << nums[5] << endl;
    //申请内存
    int *arr1 = new int[5];
    int *nums1 = new int[5]{1,2,3,4,5};
    cout << arr1[0]<< endl;// 输出结果为-1163005939，因为申请的内存空间没有初始化
    cout << nums1[4] << endl;
    // 释放内存
    delete[] arr1;
    delete[] nums1;
    // 随机访问
    cout<<randomAccess(arr, 5)<<endl;
    // 插入元素
    int len = sizeof(nums)/sizeof(nums[0]);    //求出数组的长度
    cout<<"-------------------"<<endl;
    traverse(nums,len);
    insert(nums,len,10000,2);
    cout<<"-------------------"<<endl;
    traverse(nums,len);
    // 删除元素
    remove(nums,len,2);
    traverse(nums,len);
    // 查找元素
    cout<<find(nums,len,3)<<endl;
    // 扩容数组
    int *nums2 = extend(nums,len,5);
    for(int i=5;i<len+5;i++){
        nums2[i]=i;
    }
    traverse(nums2,len+5);
    return 0;
}