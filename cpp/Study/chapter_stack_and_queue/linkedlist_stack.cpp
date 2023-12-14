/**
 * File: linkedlist_stack.cpp
 * Created Time: 2022-11-28
 * Author: qualifier1024 (2539244001@qq.com)
 */

#include "../utils/common.hpp"
class LinkedListStack{
    private:
        ListNode *stackTop;
        int stkSize;
    public:
        LinkedListStack(){
            stackTop=NULL;
            stkSize=0;
        }
        
        ~LinkedListStack(){
            freeMemoryLinkedList(stackTop);    
        }
        //获取栈的长度
        int size(){
            return stkSize;   
        }
        //判断栈是否为空
        bool isEmpty(){
            return stkSize==0;   
        }
        //入栈
        void push(int val){
            ListNode *newNode=new ListNode(val);
            newNode->next=stackTop;
            stackTop=newNode;
            stkSize++;
        }
        //出栈
        int pop(){
            if(isEmpty()){
                cout<<"栈为空，无法出栈"<<endl;
                return -1;
            }
            int num=top();
            ListNode *tmp=stackTop;
            stackTop=stackTop->next;
            stkSize--;
            int val=tmp->val;
            delete tmp;
            return val;
        }
        //获取栈顶元素
        int top(){
            if(isEmpty()){
                cout<<"栈为空，无法获取栈顶元素"<<endl;
                return -1;
            }
            return stackTop->val;
        }
        //将List 转化为 Array并返回
        vector<int> toArray(){
            vector<int> res(size());
            ListNode *node=stackTop;
            for(int i=size()-1;i>=0;i--){
                res[i]=node->val;
                node=node->next;
            }
            return res;
        }
        
};

int main(){
    return 0;
}