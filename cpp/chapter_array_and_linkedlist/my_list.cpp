#include "../utils/common.hpp"
class MyList {
    private:
        int *arr;   //数组
        int arrCapacity=10;   //数组容量
        int arrSize=0;   //数组大小（元素个数）
        int extendRatio=2;   //扩容倍数
    public:
    /*构造方法*/
        MyList(){
            arr=new int[arrCapacity];
        }
        MyList(int capacity){
            arrCapacity=capacity;
            arr=new int[arrCapacity];
        }
    /*析构方法*/
        ~MyList(){
            delete [] arr;
        }
    /*获取列表长度*/
        int size(){
            return arrSize;
        }
    /*获取列表容量*/
        int capacity(){
            return arrCapacity;
        }
    /*访问元素*/
        int get(int index){
            if(index<0||index>=arrSize){
                cout<<"index out of range"<<endl;
                return -1;
            }
            return arr[index];
        }
    /*更新元素*/
        void set(int index,int val){
            if(index<0||index>=arrSize){
                cout<<"index out of range"<<endl;
                return;
            }
            arr[index]=val;
        }
    /*列表扩容*/
    void extendCapacity(){
        int newCapacity=capacity()*extendRatio;
        int *tmp=arr;
        arr=new int[newCapacity];
        for(int i=0;i<size();i++){
            arr[i]=tmp[i];
        }
        delete [] arr;
        arrCapacity=newCapacity;
    }
    /*尾部添加元素*/
        void add(int val){
            if(arrSize==arrCapacity){
                extendCapacity();
            }
            arr[arrSize]=val;
            arrSize++;
        }
    //在指定位置添加元素
        void insert(int index,int val){
            if(index<0||index>arrSize){
                cout<<"index out of range"<<endl;
                return;
            }
            if(arrSize==arrCapacity){
                extendCapacity();
            }
            for(int i=arrSize;i>index;i--){
                arr[i]=arr[i-1];
            }
            arr[index]=val;
            arrSize++;
        }
    //删除元素
    int remove(int index){
        if(index<0||index>=arrSize){
            cout<<"index out of range"<<endl;
            return -1;
        }
        int res=arr[index];
        for(int i=index;i<arrSize-1;i++){
            arr[i]=arr[i+1];
        }
        arrSize--;
        return res;
    }
    //将列表转换为vector 主要是将后面的空间去掉 打印时不会打印出后面的空间
        vector<int> toVector(){
            vector<int> vec(size());
            for(int i=0;i<size();i++){
                vec[i]=arr[i];
            }
        }
};