#include "../utils/common.hpp"


int main(){
    //初始化栈和队列
    stack<int> stack;
    //元素入栈
    stack.push(1);
    stack.push(3);
    stack.push(4);
    stack.push(6);
    stack.push(10);
    //访问栈顶元素
    int top=stack.top();
    //元素出栈
    stack.pop();
    //获取栈的长度
    int size=stack.size();
    //判断栈是否为空
    bool empty=stack.empty();
    cout<<"top:"<<top<<endl;
    cout<<"size:"<<size<<endl;
    cout<<"empty:"<<empty<<endl;
    return 0;
}