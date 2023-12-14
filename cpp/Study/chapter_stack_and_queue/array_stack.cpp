
#include "../utils/common.hpp"

/* 基于数组实现的栈 */
class ArrayStack{
    private:
        vector <int> stack;
    public:
        //获取栈的长度
        int size(){
            return stack.size();
        }
        //判断栈是否为空
        bool isEmpty(){
            return stack.empty();
        }
        //入栈
        void push(int val){
            stack.push_back(val);
        }
        //获取栈顶元素
        int top(){
            if(isEmpty()){
                cout<<"栈为空，无法获取栈顶元素"<<endl;
                return -1;
            }
            return stack.back();
        }
        //出栈
        int pop(){
            if(isEmpty()){
                cout<<"栈为空，无法出栈"<<endl;
                return -1;
            }
            int num=top();
            stack.pop_back();
            return num;
        }
        //返回Vector
        vector<int> toArray(){
            return stack;
        }

};