#include "../utils/common.hpp"


int main(){
    //初始化列表
    vector <int> nums1;
    vector <int> nums={1,2,3,4,5};
    //访问元素
    cout<<nums[0]<<endl;
    cout<<nums[1]<<endl;
    //更新元素
    nums[0]=100;
    cout<<nums[0]<<endl;
    //插入元素
    nums.clear();
    nums.push_back(1);//在末尾插入
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    /*中间插入元素*/
    nums.insert(nums.begin()+2,100);//在第二个元素后面插入100
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    //删除元素
    nums.erase(nums.begin()+3);//删除第四个元素
    //遍历数组
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    //拼接数组
    vector <int> nums2={5,6,7,8,9};
    nums.insert(nums.end(),nums2.begin(),nums2.end());// insert()函数
    //排序列表
    sort(nums.begin(),nums.end());//sort()函数
}